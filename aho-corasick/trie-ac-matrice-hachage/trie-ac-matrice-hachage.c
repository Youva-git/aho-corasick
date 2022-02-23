//  Implantation polymorphe pour la spécification genere-ac-matrice-hachage

#include <string.h>
#include <stdlib.h>
#include "trie-ac-matrice-hachage.h"

int getWordInFile(FILE *file, char *buff, int sizeBuff) {
  char *s = fgets(buff, sizeBuff, file);
  if (s == NULL) {
    return -1;
  }
  if ((int) strlen(s) > sizeBuff) {
    fprintf(stderr,
        "La tail du mot dépasse la tail autorisé, par consiquant il ne sera pas pris en compte\nLe mot : %s",
        s);
    return -1;
  }
  strcpy(buff, s);
  (buff)[strlen(buff) - 1] = '\0';
  return 0;
}

int fillTrie(Trie trie, FILE *file) {
  char *buff = malloc(WORD_LENGTH_MAX);
  if (buff == NULL) {
    return -1;
  }
  while (getWordInFile(file, buff, WORD_LENGTH_MAX) != -1) {
    insretWordInTrie(trie, (unsigned char *) buff);
  }
  free(buff);
  return 0;
}
