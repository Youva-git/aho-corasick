//  Implantation polymorphe pour la spécification genere-texte-mots

#include <stdio.h>
#include <stdlib.h>
#include "genere-texte-mots.h"

#define FUN_SUCCESS 0
#define FUN_FAILURE -1

#define TEXT_LENGTH_MAX 1000000000
#define TEXT_LENGTH_MIN 1

#define WORD_LENGTH_MAX 255
#define WORD_LENGTH_MIN 1

#define ALPHABET_SIZE_MAX 70
#define ALPHABET_SIZE_MIN 1
#define decalageAscii 65
#define SIZE_TABLE_ASCII 127

static void genereLettrePseudoAleatoire(int sizeAlph){
  int letter = (rand() % sizeAlph + decalageAscii);
  if(letter > SIZE_TABLE_ASCII){
    letter -= ALPHABET_SIZE_MAX;
  }
  fprintf(stdout, "%c", letter);
}

void genereTextePseudoAleatoire(int lengthText, int sizeAlph) {
  for (int i = 0; i < lengthText; ++i) {
    genereLettrePseudoAleatoire(sizeAlph);
  }
  printf("\n");
}

void genereMotsPseudoAleatoire(int nbWords, int lengtWordMin, int lengtWordMax,
    int sizeAlph) {
  for (int i = 0; i < nbWords; ++i) {
    int lengtWord = rand() % (lengtWordMax - lengtWordMin + 1) + lengtWordMin;
    genereTextePseudoAleatoire(lengtWord, sizeAlph);
  }
}

int testArgumentsGenereTexte(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "***  Error : Le nombre d'arguments est incorrect\n");
    return FUN_FAILURE;
  }
  if ((atoi(argv[1]) < 1) || (atoi(argv[1]) > TEXT_LENGTH_MAX)) {
    fprintf(stderr,
        "***  Error : La longueur du texte à générer est incorrect. [1 < Longueur du texte < %d]\n",
        (TEXT_LENGTH_MAX - 1));
    return FUN_FAILURE;
  }
  if (atoi(argv[2]) < 1 || atoi(argv[2]) > ALPHABET_SIZE_MAX) {
    fprintf(stderr,
        "*** Error : La taille de l'alphabets est incorrect. [1 < Taille de l'alphabets < %d]\n",
        ALPHABET_SIZE_MAX);
    return FUN_FAILURE;
  }
  return FUN_SUCCESS;
}


int testArgumentsGenereMots(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "***  Error : Le nombre d'arguments est incorrect\n");
    return FUN_FAILURE;
  }
  if (atoi(argv[1]) < 1) {
    fprintf(stderr,
        "***  Error : Le nombre de mots à générer est incorrect. [Nombre de mots > 1]\n");
    return FUN_FAILURE;
  }
  if (atoi(argv[2]) < WORD_LENGTH_MIN || atoi(argv[2]) > WORD_LENGTH_MAX - 1) {
    fprintf(stderr,
        "*** Error : La longueur minimale du mots est incorrect. [%d < longueur minimale du mots < %d]\n",
        WORD_LENGTH_MIN, (WORD_LENGTH_MAX - 1));
    return FUN_FAILURE;
  }
  if (atoi(argv[3]) < atoi(argv[2])) {
    fprintf(stderr,
        "*** Error : La longueur maximale du mot doit étre supérieur ou égale a sa longueur minimale \n");
    return FUN_FAILURE;
  }
  if (atoi(argv[4]) < WORD_LENGTH_MIN || atoi(argv[4]) > WORD_LENGTH_MAX - 1) {
    fprintf(stderr,
        "*** Error : La longueur maximale du mot est incorrect. [%d < longueur maximale du mots < %d]\n",
        WORD_LENGTH_MIN, (ALPHABET_SIZE_MAX - 1));
    return FUN_FAILURE;
  }
  if (atoi(argv[4]) < ALPHABET_SIZE_MIN || atoi(argv[4]) > ALPHABET_SIZE_MAX) {
    fprintf(stderr,
        "*** Error : La taille de l'alphabets est incorrect. [%d < Taille de l'alphabets < %d]\n",
        ALPHABET_SIZE_MIN, ALPHABET_SIZE_MAX);
    return FUN_FAILURE;
  }
  return FUN_SUCCESS;
}
