#ifndef LIST_H
#define LIST_H

#include "slowo.h"

typedef struct {
	slowo * slowo;
	struct wezel_t * next;
} wezel_t;
  
typedef struct {
	wezel_t * ost;
	wezel_t * pierw;
	int dlugosc;
} lista_t;
  
lista_t * n_lista ();
lista_t * dodaj_lista (lista_t * lista, slowo_t * slowo);

#endif