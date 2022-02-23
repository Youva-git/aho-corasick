genereTexteMotsdir = genere-texte-mots/
ahoCorasickdir = aho-corasick/
trieAcMatriceHachagedir = aho-corasick/trie-ac-matrice-hachage/
filedir = aho-corasick/file/

CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 -I$(genereTexteMotsdir) -I$(ahoCorasickdir) -I$(trieAcMatriceHachagedir) -I$(filedir) -DHOLDALL_INSERT_TAIL 
LDFLAGS = 
VPATH = $(genereTexteMotsdir):$(ahoCorasickdir):$(trieAcMatriceHachagedir):$(filedir) 
OBJ = $(wildcard *.o) $(genereTexteMotsdir)genere-texte-mots.o $(ahoCorasickdir)aho-corasick.o $(trieAcMatriceHachagedir)trie-ac-hachage.o $(trieAcMatriceHachagedir)trie-ac-matrice.o $(filedir)file.o
CC = gcc
EXEC = genere-texte genere-mots ac-matrice ac-hachage 
all : $(EXEC)

clean :
	$(RM) $(OBJ) $(EXEC)

genere-texte: genere-texte.o genere-texte-mots.o 
	$(CC) -o $@ $^
	
genere-mots: genere-mots.o genere-texte-mots.o 
	$(CC) -o $@ $^

ac-matrice: main-ac-matrice-hachage.o aho-corasick.o trie-ac-matrice.o trie-ac-matrice-hachage.o file.o
	$(CC) -o $@ $^

ac-hachage: main-ac-matrice-hachage.o aho-corasick.o trie-ac-hachage.o trie-ac-matrice-hachage.o file.o
	$(CC) -o $@ $^


genere-texte-mots.o : genere-texte-mots.c
	$(CC) -o $@ -c $<

aho-corasick.o : aho-corasick.c 
	$(CC) -o $@ -c $<

trie-ac-matrice-hachage.o : trie-ac-matrice-hachage.c
	$(CC) -o $@ -c $<
	
trie-ac-matrice.o : trie-ac-matrice.c
	$(CC) -o $@ -c $<
	
trie-ac-hachage.o : trie-ac-hachage.c
	$(CC) -o $@ -c $<

file.o : file.c
	$(CC) -o $@ -c $<

%.o : %.c
	$(CC) -o $@ -c $<
