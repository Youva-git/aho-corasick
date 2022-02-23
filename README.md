## Aide d'utitilisation des programmes implémenter:  
  
### makefile  
Usage:   
* make : pour créer les exécutables (genere-texte genere-mots ac-matrice ac-hachage).  
* make clean : pour supprimer les fichiers .o et les exécutables généré.  
  
1. Génération pseudo-aléatoire d'un texte.  
(C'est tout ce passe bien renvoie le texte généré sur la sortie standard.)  
Usage:  
./genere-texte [longueur_du texte] [taille_de l'alphabet du texte]  
Exemple:  
./genere-texte 100 2  
Génère un texte de longueur 100 avec un alphabet de taille 2 Résultats.  
  
2. Génération pseudo-aléatoire d'un ensemble de mots.  
(C'est tout ce passe bien renvoie l'ensemble de mots générés sur la sortie standard.)  
Usage:  
./genere-mots [nombre_de mots] [longueur minimale des mots] [longueur maximale des mots] [taille_de l'alphabet des mots]  
Exemple:  
./genere-mots 10 2 5 3  
Génère un ensmble de 10 mots de taille variable (entre 2 et 5) avec un alphabet de taille 3.  
  
3. Compter le nombre d’occurrences exactes d’un ensemble de k mots dans un texte, a l'aide de l'algorithme d'aho-corasick :  
* en utilisant l'implémentation de matrice de transitions.  
* en utilisant l'implémentation de table de hacahge.  
(C'est tout ce passe bien renvoie tous les deux le nombre d’occurrences exactes d’un ensemble de k mots dans un texte)  
Usage: matrice de transitions & table de hachage  
./ac-matrice [chemin vers le fichier contenant un ensemble de mots] [chemin vers le fichier contenant un texte]  
./ac-hachage [chemin vers le fichier contenant un ensemble de mots] [chemin vers le fichier contenant un texte]  
Exemple: matrice de transitions & table de hachage  
./ac-matrice mots.txt texte.txt  
./ac-hachage mots.txt texte.txt  
Affiche tous les deux le nombre d’occurrences exactes de l'ensemble de mots du fichier mots.txt dans le texte du fichier texte.txt.  
