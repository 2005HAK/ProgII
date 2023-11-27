#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no no_t;
typedef struct lista lista_t;
typedef int tipo;

lista_t **criaContainers(int tam);

lista_t *lista_cria();

void lista_destroi(lista_t **l);

int lista_inicializada(lista_t *l);

int lista_info_cauda(lista_t *l, int *dado);

int lista_insere_cauda(lista_t *l, tipo dado);

int lista_remove_cauda(lista_t *l, tipo *dado);

int lista_busca_info(lista_t *l, tipo dado);

void lista_imprime(lista_t *l);

void moveAAboveB (lista_t **c, int a, int b, int tam);

void moveAUpB (lista_t **c, int a, int b, int tam);

void stackingAAboveB (lista_t **c, int a, int b, int tam);

void stackingAUpB (lista_t **c, int a, int b, int tam);

void exitContainers (lista_t **c, int tam);

#endif