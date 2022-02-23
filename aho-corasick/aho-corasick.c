//  Implantation polymorphe pour la spécification aho-corasick

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "aho-corasick.h"
#include "file/file.h"

struct _ac {
  Trie trie;
  int supp[];
};

AC completer(AC ac) {
  file *f = file_empty(sizeTrie(ac->trie));
  if (f == NULL) {
    return NULL;
  }
  for (size_t i = 0; i <= UCHAR_MAX; ++i) {
    int p = getTransition(ac->trie, 0, (unsigned char) i);
    if (p != 0) {
      file_push(f, p);
      ac->supp[p] = 0;
    }
  }
  while (!file_is_empty(f)) {
    int node = file_pop(f);
    for (size_t i = 0; i <= UCHAR_MAX; ++i) {
      int p = getTransition(ac->trie, node, (unsigned char) i);
      if (p != -1) {
        file_push(f, p);
        int s = ac->supp[node];
        while (getTransition(ac->trie, s, (unsigned char) i) == -1) {
          s = ac->supp[s];
        }
        ac->supp[p] = getTransition(ac->trie, s, (unsigned char) i);
        addNodeFini(ac->trie, p, getNodeFini(ac->trie, ac->supp[p]));
      }
    }
  }
  file_dispose(&f);
  return ac;
}

int entrer(Trie trie, FILE *fmots) {
  if (fillTrie(trie, fmots)) {
  }
  initTrie(trie);
  return 0;
}

AC pre_AC(FILE *fmots, int maxNode) {
  Trie trie = trie_empty(maxNode);
  if (trie == NULL) {
    return NULL;
  }
  entrer(trie, fmots);
  struct _ac *ac = malloc((sizeof *ac) + sizeTrie(trie) * (sizeof(size_t)));
  if (ac == NULL) {
    return NULL;
  }
  ac->trie = trie;
  if (completer(ac) == NULL) {
    AC_dispose(&ac);
    return NULL;
  }
  return ac;
}

size_t Ac(FILE *fmots, int nbMots, char *texte, size_t lengthTexte) {
  AC ac = pre_AC(fmots, nbMots);
  size_t nbOcc = 0;
  int node = 0;
  for (size_t j = 0; j < lengthTexte; ++j) {
    while (getTransition(ac->trie, node, (unsigned char) texte[j]) == -1) {
      node = ac->supp[node];
    }
    node = getTransition(ac->trie, node, (unsigned char) texte[j]);
    if (node != -1 && getNodeFini(ac->trie, node) != 0) {
      nbOcc += getNodeFini(ac->trie, node);
    }
  }
  AC_dispose(&ac);
  return nbOcc;
}

void AC_dispose(AC *ac) {
  trie_dispose((&(*ac)->trie));
  free(*ac);
  *ac = NULL;
}
