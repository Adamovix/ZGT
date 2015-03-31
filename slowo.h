#ifndef SLOWO_H
#define SLOWO_H

typedef struct {
	int * wekt;
	int dlugosc;
	int rozmiar;
} powt_t;

typedef struct {
	int indeks;
	powt_t * powt;
} slowo_t;

slowo_t * n_slowo (char * string, int indeks);

#endif