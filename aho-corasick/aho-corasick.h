//  Interface polymorphe pour la spécification aho-corasick

#ifndef AHOCORASICK_H
#define AHOCORASICK_H
#include <stdio.h>
#include "trie-ac-matrice-hachage/trie-ac-matrice-hachage.h"

//  struct _ac, AC : structure regroupant les informations permettant de gérer
//    un trie avec la fonction de suppléance.La création de la structure de
//    données associée est confiée à la fonction pre_AC.
typedef struct _ac *AC;

//  pre_Ac : Crée un trie d'une taille nbMots et le rempli avec l'ensomble des
//    mots contenue dans le fichier pointé par *fMots puis défini ces
//    transitions et ces liens de suppléance. Renvoie NULL en cas de dépassement
//    de capacité. Renvoie sinon un pointeur vers l'objet qui gère la structure
//    de données (trie).
extern AC pre_AC(FILE *fmots, int nbMots);

//  entrer : rempli le trie pointé par trie avec l'ensomble des mots contenue
//    dans le fichier pointé par *fMots est initialise le trie. Renvoie -1 en
//    cas d'erreur 0 sinon.
extern int entrer(Trie trie, FILE *fMots);

//  completer : Fonction de suppléance qui compléte les liens de suppléance.
extern AC completer(AC ac);

// _Ac : trouve toutes les occurrences d’un ensemble de mots contenue dans un
//    fichier pointé par *fMots de nbMots mots dans un texte stoké dans la
//    chaine de caractaire pointé par *texte de longueur lengthTexte.
extern size_t Ac(FILE *fMots, int nbMots, char *texte, size_t lengthTexte);

//  AC_dispose : si *ac ne vaut pas NULL, libère les ressources allouées à
//    la structure de donnée associée à *ac puis affecte à *ac la valeur NULL
extern void AC_dispose(AC *ac);

#endif


