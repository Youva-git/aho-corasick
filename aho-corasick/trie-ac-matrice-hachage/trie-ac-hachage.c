//  Implantation polymorphe pour la spécification genere-ac-matrice-hachage

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "trie-ac-matrice-hachage.h"

#define RATE_FILING 0.75

struct _list {
  int startNode;
  int targetNode;
  unsigned char letter;
  struct _list *next;
};

struct _trie {
  int maxNode;
  int nextNode;
  List *transition;
  size_t *finite;
};

size_t sizeTH(int maxNode) {
  return (size_t) (((maxNode)) / RATE_FILING);
}


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
  trie->transition = malloc(sizeTH(maxNode) * sizeof *trie->transition);
  if (trie->transition == NULL) {
    return NULL;
  }
  for (List *trs = trie->transition;
      trs < trie->transition + sizeTH(maxNode); ++trs) {
    *trs = NULL;
  }
  trie->finite = malloc((size_t) maxNode * sizeof(*trie->finite));
  if (trie->finite == NULL) {
    return NULL;
  }
  for (size_t *p = trie->finite; p < trie->finite + maxNode; ++p) {
    *p = 0;
  }
  return trie;
}

size_t sizeTrie(Trie trie) {
  return (size_t) trie->nextNode;
}

static size_t funHachage(int node, unsigned char letter) {
  return (size_t) (node * UCHAR_MAX + letter);
}

int getTransition(struct _trie *trie, int node, unsigned char letter) {
  size_t index = funHachage(node, letter) % sizeTH(trie->maxNode);
  int next = -1;
  List trs = trie->transition[index];
  while (trs != NULL && next == -1) {
    if (trs->startNode == node && trs->letter == letter) {
      next = trs->targetNode;
    }
    trs = trs->next;
  }
  return next;
}

static int addTransition(struct _trie *trie, int startNode,
    unsigned char letter, int targetNode) {
  struct _list *newTransition = malloc(sizeof *newTransition);
  if (newTransition == NULL) {
    return -1;
  }
  newTransition->startNode = startNode;
  newTransition->targetNode = targetNode;
  newTransition->letter = letter;
  size_t tableSize = sizeTH(trie->maxNode);
  size_t index = funHachage(startNode, letter) % tableSize;
  newTransition->next = trie->transition[index];
  trie->transition[index] = newTransition;
  return 0;
}

void insretWordInTrie(Trie trie, unsigned char *word) {
  int old = 0;
  int curr = 0;
  unsigned char *p = word;
  while (*p != '\0' && curr != -1) {
    old = curr;
    curr = getTransition(trie, curr, *p);
    ++p;
  }
  if (curr == -1) {
    curr = old;
    --p;
    if (strlen((char *) p) > (size_t) (trie->maxNode - trie->nextNode)) {
      printf("Error: maximum number of nodes exceeded\n");
      return;
    }
    while (*p != '\0') {
      addTransition(trie, curr, *p, trie->nextNode);
      curr = trie->nextNode;
      ++trie->nextNode;
      ++p;
    }
  }
  ++trie->finite[curr];
}


size_t getNodeFini(Trie trie, int node) {
  return trie->finite[node];
}

void addNodeFini(Trie trie, int node, size_t nbOcc) {
  trie->finite[node] += nbOcc;
}

void initTrie(Trie trie) {
  for (size_t c = 0; c <= UCHAR_MAX; c++) {
    if (getTransition(trie, 0, (unsigned char) c) == -1) {
      addTransition(trie, 0, (unsigned char) c, 0);
    }
  }
}

void trie_dispose(struct _trie **trie) {
  if (*trie != NULL) {
    size_t tableSize = sizeTH((*trie)->maxNode);
    for (List *t = (*trie)->transition;
        t < (*trie)->transition + tableSize; ++t) {
      while (*t != NULL) {
        struct _list *tmp = *t;
        *t = (*t)->next;
        free(tmp);
      }
    }
    free((*trie)->transition);
    free((*trie)->finite);
    free(*trie);
    *trie = NULL;
  }
}
