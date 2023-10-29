#ifndef conjunto_privado_h
#define conjunto_privado_h

#include "conjunto_interface.h"
#include <limits.h>

#define ELEMENTOS 10
#define ELEM_MAX INT_MAX
#define ELEM_MIN INT_MIN

typedef int elem_t;

typedef struct conjunto {
	elem_t *vetor;
	int numero;
	int capacidade;
} conjunto_t;

//Operacoes privadas ao TDA que por ventura sejam necessarias

#endif
