//  Interface polymorphe pour la spécification genere-texte-mots

#ifndef GEBERE_TEXTE_MOTS_H
#define GEBERE_TEXTE_MOTS_H

// genereTextePseudoAleatoire : genere pseudo-aléatoirement un texte de taille
//    lengthText avec un alphabet de taille sizeAlph.
extern void genereTextePseudoAleatoire(int lengthText, int sizeAlph);

// testArgumentsGenereTexte : teste les arguments de l'exécutable de
//    genere-texte Renvoi -1 en cas d'erreur est 0 Sinon.
extern int testArgumentsGenereTexte(int argc, char *argv[]);

// genereMotsPseudoAleatoire : genere pseudo-aléatoirement un ensemble de mots
//    de taille nbWords de longueur minimale de lengtWordMin et la longueur
//    maximale de lengtWordMax pour chaque mot avec un alphabet de taille
//    sizeAlph.
extern void genereMotsPseudoAleatoire(int nbWords, int lengtWordMin,
    int lengtWordMax,
    int sizeAlph);

// testArgumentsGenereMots : teste les arguments de l'exécutable de
//    genere-mots Renvoi -1 en cas d'erreur est 0 Sinon.
extern int testArgumentsGenereMots(int argc, char *argv[]);
#endif
