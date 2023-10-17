#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

struct lista {
    int tamanho;
    struct no *primeiro;
};