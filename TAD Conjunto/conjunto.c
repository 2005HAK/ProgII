#include "conjunto_privado.h"
#include <stdlib.h>
#include <stdio.h>

conjunto_t *conjunto_cria(void){
    conjunto_t *conjunto = (conjunto_t *)malloc(sizeof(conjunto_t));
    if (conjunto != NULL){
        (conjunto->capacidade) = ELEMENTOS;
        (conjunto->vetor) = (elem_t *)malloc((conjunto->capacidade) * sizeof(elem_t));
        if ((conjunto->vetor) == NULL){
            free(conjunto);
            return NULL;
        } 
        conjunto_inicializa_vazio(conjunto);
        return conjunto;
    } return NULL;
}

void conjunto_destroi(conjunto_t **a){
    if (a != NULL){
        if((*a) != NULL){
            if (((*a)->vetor)){
                free((*a)->vetor);
                ((*a)->vetor) = NULL;
            }
            free(*a);
            *a = NULL;
            a = NULL;
        } else a = NULL;
    } 
}

int conjunto_numero_elementos(conjunto_t *a){
    if (a != NULL){
        if(a->numero > 0) return (a->numero);
        return 0;
    } return 0;
}

void conjunto_inicializa_vazio(conjunto_t *a){
    if (a != NULL) (a->numero) = 0;
}

void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if (a != NULL && b != NULL && c != NULL){
        int i;

        if ((a->numero) > 0 || (b->numero) > 0){
            if (c->vetor) free(c->vetor);

            (c->capacidade) = ELEMENTOS;
            (c->vetor) = (elem_t *)malloc(sizeof(elem_t) * (c->capacidade));
            if((c->vetor) != NULL){
                conjunto_inicializa_vazio(c);

                for (i = 0; i < (a->numero); i++) conjunto_insere_elemento((a->vetor)[i], c);
                for (i = 0; i < (b->numero); i++) conjunto_insere_elemento((b->vetor)[i], c);
            } else free(c);
        }
    }
}

void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){  
    if (a != NULL && b != NULL && c != NULL){
        int i, j;

        if ((a->numero) > 0 && (b->numero) > 0){
            if (c->vetor) free(c->vetor);

            (c->capacidade) = ELEMENTOS;
            (c->vetor) = (elem_t *)malloc(sizeof(elem_t) * (c->capacidade));
            if((c->vetor) != NULL){
                conjunto_inicializa_vazio(c);

                for (i = 0; i < (a->numero); i++) 
                    for (j = 0; j < (b->numero); j++) if ((a->vetor)[i] == (b->vetor)[j]) conjunto_insere_elemento((a->vetor)[i], c);
            } else free(c);
        }
    }
}

void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if (a != NULL && b != NULL && c != NULL){
        int i, j, verifica = 0;

        if ((a->numero) > 0 || (b->numero) > 0){
            if (c->vetor) free(c->vetor);

            (c->capacidade) = ELEMENTOS;
            (c->vetor) = (elem_t *)malloc(sizeof(elem_t) * (c->capacidade));
            if((c->vetor) != NULL){
                conjunto_inicializa_vazio(c);

                for (i = 0; i < (a->numero); i++){
                    for (j = 0; j < (b->numero); j++) if ((a->vetor)[i] == (b->vetor)[j]) verifica = 1;
                    if (verifica == 0) conjunto_insere_elemento((a->vetor)[i], c);
                    verifica = 0;
                }
                for (i = 0; i < (b->numero); i++){
                    for (j = 0; j < (a->numero); j++) if ((b->vetor)[i] == (a->vetor)[j]) verifica = 1;
                    if (verifica == 0) conjunto_insere_elemento((b->vetor)[i], c);
                    verifica = 0;
                }
            } else free(c);
        }
    }
}

int conjunto_membro(elem_t x, conjunto_t *a){ 
    if (a != NULL){
        int i;

        for (i = 0; i < (a->numero); i++) if (x == (a->vetor)[i]) return 1;
        return 0;
    } return 0;
}

int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    if (a != NULL){
        int i;

        for (i = 0; i < (a->numero); i++) if (x == (a->vetor)[i]) return 1;

        if ((a->numero) == (a->capacidade)){
            (a->vetor) = (elem_t*) realloc((a->vetor), ((a->capacidade) + 10) * sizeof(elem_t));
            if ((a->vetor) == NULL) return 0;
            (a->capacidade) += 10;
        }
        (a->vetor)[a->numero] = x;
        (a->numero)++;
        return 1;
    } return 0;
}

void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    if (a != NULL){
        int i;

        if ((a->numero) > 0){
            for (i = 0; i < (a->numero); i++){
                if (x == (a->vetor)[i]){
                    for (i; i < (a->numero); i++){
                        if (i != (a->numero) - 1) (a->vetor)[i] = (a->vetor)[i + 1];
                        else (a->vetor)[i] = 0;
                    }
                    (a->numero)--;
                    if ((a->capacidade) > 10 && ((a->capacidade) - (a->numero)) == 11){
                        (a->vetor) = (elem_t*) realloc((a->vetor), ((a->capacidade) - 10) * sizeof(elem_t));
                        if ((a->vetor) != NULL) (a->capacidade) -= 10;
                    }
                }
            }
        }
    }
}

void conjunto_atribui(conjunto_t *a, conjunto_t *b){
    if (a != NULL && b != NULL){
        int i;

        if ((b->vetor) != NULL) free(b->vetor);

        (b->capacidade) = (a->capacidade);
        (b->vetor) = (elem_t *)malloc(sizeof(elem_t) * (b->capacidade));
        if ((b->vetor) != NULL){
            conjunto_inicializa_vazio(b);

            for (i = 0; i < (a->numero); i++) conjunto_insere_elemento((a->vetor)[i], b);
        } else free(b);
    }
}

int conjunto_igual(conjunto_t *a, conjunto_t *b){
    if (a != NULL && b != NULL){
        int i, j, verifica = 0;

        if ((a->numero) == (b->numero)){
            for (i = 0; i < (a->numero); i++){
                for (j = 0; j < (b->numero); j++) if ((a->vetor)[i] == (b->vetor)[j]) verifica = 1;
                if (verifica == 0) return 0;
                verifica = 0;
            } return 1;
        } return 0;
    } return 0;
}

elem_t conjunto_minimo(conjunto_t *a){
    if (a != NULL){
        if ((a->vetor) != NULL && (a->numero) > 0){
            int i, minimo = (a->vetor)[0];

            for (i = 0; i < (a->numero); i++) if ((a->vetor)[i] < minimo) minimo = (a->vetor)[i];
            return minimo;
        } return ELEM_MAX;         
    } return ELEM_MAX;
}

elem_t conjunto_maximo(conjunto_t *a){
    if (a != NULL){
        if ((a->vetor) != NULL && (a->numero) > 0){
            int i, maximo = (a->vetor)[0];

            for (i = 0; i < (a->numero); i++) if ((a->vetor)[i] > maximo) maximo = (a->vetor)[i];
            return maximo;
        } return ELEM_MIN; 
    } return ELEM_MIN;
}

void conjunto_imprime(conjunto_t *a){
    if (a != NULL){
        int i;
        if ((a->vetor) != NULL && (a->numero) > 0){
            for (i = 0; i < (a->numero); i++){
                if ((i + 1) == (a->numero)) printf("%i\n", (a->vetor)[i]);
                else printf("%i ", (a->vetor)[i]);
            }
        }
    }
}