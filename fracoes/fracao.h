#include <stdio.h>
#include <stdlib.h>

#ifndef fracao_h
#define fracao_h

typedef struct fracao fracao_t;

void imprime_fracao(fracao_t *f);
fracao_t* cria_fracao(int n, int d);
void destroi_fracao(fracao_t ** f);

#endif