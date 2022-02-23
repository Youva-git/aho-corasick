//  Implantation polymorphe pour la spécification genere-ac-matrice-hachage

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "trie-ac-matrice-hachage.h"

struct _trie {
  int maxNode;
  int nextNode;
  int **transition;
  size_t *finite;
};

Trie trie_empty(int maxNode) {
  if (maxNode < 1) {
    return NULL;
  }
  Trie trie = malloc(sizeof *trie);
  if (trie == NULL) {
    return NULL;
  }
  trie->maxNode = maxNode;
  trie->nextNode = 1;
  trie->transition = malloc((size_t) maxNode * sizeof(*trie->transition));
  if (trie->transition == NULL) {
    return NULL;
  }
  for (int **p = trie->transition; p < trie->transition + maxNode; ++p) {
    *p = malloc(((size_t) UCHAR_MAX) * sizeof *p);
    if (*p == NULL) {
      return NULL;
    }
    for (int *q = *p; q <= *p + UCHAR_MAX; ++q) {
      *q = -1;
    }
  }
  trie->finite = malloc((size_t) maxNode * sizeof(*trie->finite));
  if (trie->finite == NULL) {
    return NULL;
  }
  for (size_t *p = trie->finite; p < (trie->finite + maxNode); ++p) {
    *p = 0;
  }
  return trie;
}

size_t sizeTrie(Trie trie) {
  return (size_t) trie->nextNode;
}

void insretWordInTrie(Trie trie, unsigned char *word) {
  struct _trie *t = trie;
  int old = 0;
  int curr = 0;
  unsigned char *p = word;
  while (*p != '\0' && curr != -1) {
    old = curr;
    curr = t->transition[curr][*p];
    ++p;
  }
  if (curr == -1) {
    curr = old;
    --p;
    if (strlen((char *) p) > (size_t) (t->maxNode - t->nextNode)) {
      printf("*** Error: Le nombre maximum de nodes est atteint\n");
      return;
    }
    while (*p != '\0') {
      t->transition[curr][*p] = t->nextNode;
      curr = t->nextNode;
      ++t->nextNode;
      ++p;
    }
  }
  ++t->finite[curr];
}

int getTransition(Trie trie, int node, unsigned char letter) {
  return trie->transition[node][letter];
}

size_t getNodeFini(Trie trie, int node) {
  return trie->finite[node];
}

void addNodeFini(Trie trie, int node, size_t nbOcc) {
  trie->finite[node] += nbOcc;
}

void initTrie(Trie trie) {
  int *start = trie->transition[0];
  for (int *p = start; p <= start + UCHAR_MAX; p++) {
    if (*p == -1) {
      *p = 0;
    }
  }
}

void trie_dispose(Trie *trie) {
  if (*trie == NULL) {
    return;
  }
  for (int **p = (*trie)->transition;
      p < (*trie)->transition + (*trie)->maxNode;
      ++p) {
    free(*p);
  }
  free((*trie)->transition);
  free((*trie)->finite);
  free(*trie);
  *trie = NULL;
}
