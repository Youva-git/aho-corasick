#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "aho-corasick/aho-corasick.h"

#define TEXT_LENGTH_MAX 1000000000

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s mots.txt texte.txt\n", argv[0]);
    return EXIT_FAILURE;
  }
  FILE *fMots = fopen(argv[1], "r");
  if (fMots == NULL) {
    fprintf(stderr, "Error: failed to open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  FILE *fTexte = fopen(argv[2], "r");
  if (fTexte == NULL) {
    fclose(fMots);
    fprintf(stderr, "Error: failed to open file %s\n", argv[2]);
    return EXIT_FAILURE;
  }
  fseek(fMots, 0, SEEK_END);
  int lengthMots = (int) ftell(fMots);
  rewind(fMots);
  
  char *buff = malloc(TEXT_LENGTH_MAX);
  if (buff == NULL) {
    return EXIT_FAILURE;
  }
  char *s = fgets(buff, TEXT_LENGTH_MAX, fTexte);
  if (s == NULL) {
    return EXIT_FAILURE;
  }
  fclose(fTexte);
  printf(" %lu\n", Ac(fMots, lengthMots, buff, strlen(buff)));
  fclose(fMots);
  free(buff);
  return EXIT_SUCCESS;
}
