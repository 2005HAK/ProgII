#include "abb_privado.h"

/* Coloque abaixo as suas implementações */

void abb_destroi_rec(no_t *n){
    if(n == NULL) return;

    abb_destroi_rec(n->esq);

    abb_destroi_rec(n->dir);

    free(n);

    n = NULL;

    return;
}