#ifndef TABLICA_H
#define TABLICA_H

#include "slowo.h"

typedef struct {
	slowo_t ** wekt;
	int rozmiar;
} tablica_t;

tablica_t * n_tablica (int size);

#endif