//  Interface polymorphe pour la spécification trie-ac-matrice trie-ac-hachage
//    genere-ac-matrice-hachage

#ifndef TRIEACMATRICEHACHAGE_H
#define TRIEACMATRICEHACHAGE_H
#include <stdio.h>
#include <stdbool.h>

#define WORD_LENGTH_MAX 255

//  struct _list, List : structure regroupant les informations permettant de
//    gérer une List dont les éléments sont des entiers et des caractaires.
typedef struct _list *List;

//  struct _trie, Trie : structure regroupant les informations permettant de
//    gérer une Trie dont les éléments sont des entiers . La création
//    de la structure de données associée est confiée à la fonction file_empty.
typedef struct _trie *Trie;

//  trie_empty : Crée une structure de données correspondant initialement au
//    trie vide. Renvoie NULL en cas de dépassement de capacité. Renvoie sinon
//    un pointeur vers l'objet qui gère la structure de données.
extern Trie trie_empty(int maxNode);

//  entrer : Rempli le trie pointé par trie avec l'ensomble des mots contenue
//    dans le fichier pointé par *file. Renvoie -1 en cas d'erreur 0 sinon
extern int fillTrie(Trie trie, FILE *file);

// getWordInFile : stocke dans la chaine de caractaire pointer par *buff les
//    sizeBuff premier éléments de la ligne du cresusre du fichier pointer par
//    file. Renvoie -1 en cas de dépassement de capacité. Renvoie sinon 0.
extern int getWordInFile(FILE *file, char *buff, int sizeBuff);

// insretWordInTrie : insére le mot pointer par *w dans le trie.
extern void insretWordInTrie(Trie trie, unsigned char *word);

// getTransition : renvoie la valeur de la transition de la lettre dans le trie
extern int getTransition(Trie trie, int node, unsigned char letter);

// initTrie : initialise les transition du trie.
extern void initTrie(Trie trie);

// getNodeFini : renvoie le nombre d'états finaux du trie.
extern size_t getNodeFini(Trie trie, int node);

// SizeTrie : renvoie la tail du trie pointer par trie.
extern size_t sizeTrie(Trie trie);

// addNodeFini : insére le node passer en paramétre dans le trie et lui ajoute
//    nbOcc pour créer l'état final.
extern void addNodeFini(Trie trie, int node, size_t nbOcc);

//  trie_dispose : si *trie ne vaut pas NULL, libère les ressources allouées à
//    la structure de donnée associée à *trie puis affecte à *trie la valeur
//    NULL
void trie_dispose(Trie *trie);

#endif
