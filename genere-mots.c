#include <stdio.h>
#include <stdlib.h>
#include "genere-texte-mots/genere-texte-mots.h"

int main(int argc, char *argv[]) {
  if (testArgumentsGenereMots(argc, argv) != 0) {
    return EXIT_FAILURE;
  }
  genereMotsPseudoAleatoire(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]),
      atoi(argv[4]));
  return EXIT_SUCCESS;
}
