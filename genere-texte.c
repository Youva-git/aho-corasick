#include <stdio.h>
#include <stdlib.h>
#include "genere-texte-mots/genere-texte-mots.h"

int main(int argc, char *argv[]) {
  if (testArgumentsGenereTexte(argc, argv) != 0) {
    return EXIT_FAILURE;
  }
  genereTextePseudoAleatoire(atoi(argv[1]), atoi(argv[2]));
  return EXIT_SUCCESS;
}

