//  Interface polymorphe pour la spécification FILE

#ifndef FILE__H
#define FILE__H

#include <stdbool.h>
#include <stddef.h>

//  struct file, file : structure regroupant les informations permettant de
//    gérer une file dont les éléments sont des entiers. La création
//    de la structure de données associée est confiée à la fonction file_empty.
typedef struct file file;

//  struct cfile, cfile : gestion des adresses des éléments dans la file à
//    l'aide d'une liste dynamique simplement chainée avec un pointeur de tete
//    et de queue.
typedef struct cfile cfile;

//  file_empty : crée une structure de données correspondant initialement à la
//    file vide. Renvoie NULL en cas de dépassement de capacité. Renvoie sinon
//    un pointeur vers l'objet qui gère la structure de données
extern file *file_empty(size_t heightFile);

//  file_push : enfile xptr sur la file associée à s. Renvoie -1 si xptr < 0
//   ou en cas de dépassement de capacité. Renvoie sinon xptr
extern int file_push(file *s, int xptr);

//  file_pop : défile la file associée à s. Renvoie -1 si la fille est vide.
//    Renvoie sinon l'entier qui était au début de la file.
extern int file_pop(file *s);

//  file_is_empty : renvoie true ou false selon que la file associée à s est
//    vide ou non
extern bool file_is_empty(const file *s);

//  file_dispose : si *sptr ne vaut pas NULL, libère les ressources allouées à
//    la structure de donnée associée à *sptr puis affecte à *sptr la valeur
//    NULL
extern void file_dispose(file **sptr);

#endif
