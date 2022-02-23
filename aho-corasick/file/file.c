//  Implantation polymorphe pour la spécification FILE

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

struct cfile {
  int value;
  cfile *next;
};

struct file {
  cfile *head;
  cfile *tail;
  size_t height;
  size_t heightMax;
};

file *file_empty(size_t heightFile) {
  file *s = malloc(sizeof *s);
  if (s == NULL) {
    return NULL;
  }
  s->head = NULL;
  s->head = NULL;
  s->height = 0;
  s->heightMax = heightFile;
  return s;
}

int file_push(file *s, int xptr) {
  if (xptr < 0) {
    return -1;
  }
  if (s->height == s->heightMax) {
    fprintf(stderr, "***Error : La file est complet\n");
    return -1;
  }
  cfile *p = malloc(sizeof *p);
  if (p == NULL) {
    return -1;
  }
  if (file_is_empty(s)) {
    s->head = p;
  } else {
    s->tail->next = p;
  }
  p->value = xptr;
  p->next = NULL;
  s->tail = p;
  s->height += 1;
  return 0;
}

int file_pop(file *s) {
  if (s->height == 0) {
    return -1;
  }
  cfile *p = s->head;
  s->head = p->next;
  int xptr = p->value;
  free(p);
  s->height -= 1;
  return xptr;
}

bool file_is_empty(const file *s) {
  return s->height == 0;
}

size_t file_height(const file *s) {
  return s->height;
}

void file_dispose(file **sptr) {
  if (*sptr == NULL) {
    return;
  }
  cfile *p = (*sptr)->head;
  while (p != NULL) {
    cfile *t = p;
    p = p->next;
    free(t);
  }
  free(*sptr);
  *sptr = NULL;
}
