#include <stdio.h>
#include <stdlib.h>

#ifndef interface_racional_h
#define interface_racional_h

/* Define aqui as estruturas do TDA */
typedef struct racional racional_t;

/* operações do TDA */
racional_t *cria_racional(int numerador, int denominador);
void destroi_racional(racional_t ** pp);
racional_t *soma_racional(racional_t * a, racional_t * b);
racional_t *multi_racional(racional_t *a, racional_t *b);
int igualdade_racional(racional_t *a, racional_t *b);
void reduz_racional(racional_t *p);
void mostra_racional(racional_t *p);

#endif
