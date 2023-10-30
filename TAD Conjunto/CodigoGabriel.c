#include "conjunto_privado.h"
#include <stdlib.h>
#include <stdio.h>

conjunto_t *conjunto_cria(void){
    conjunto_t *cria = (conjunto_t*) malloc (sizeof(conjunto_t));
    if(cria == NULL) return NULL;
    cria -> capacidade = ELEMENTOS;
    cria -> vetor = (int*) malloc (sizeof(int)*(cria -> capacidade));
    if(cria -> vetor == NULL) return NULL;
    return cria;
}
 
void conjunto_destroi(conjunto_t **a){
    if(a != NULL && *a != NULL){
        if((*a) -> vetor != NULL){
            free( (*a) -> vetor );
            (*a) -> vetor = NULL;
        }
        free(*a);
        *a = NULL;
        a = NULL;
    }
    else if(a != NULL && *a == NULL){
        a = NULL;
    }
}

int conjunto_numero_elementos(conjunto_t *a){
    if (a != NULL && (a -> numero) >= 0){
        int b = (a -> numero);
        return b;
    } return 0; 
}

void conjunto_inicializa_vazio(conjunto_t *a){
    if(a != NULL) (a -> numero) = 0;
}

void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a != NULL && b != NULL && c != NULL){
        int i, j, k, igual = 0;
        (c -> capacidade) = ((a -> numero) + (b -> numero));
        if((c -> capacidade) > 0){
            c -> vetor = (int*) realloc ((c -> vetor), sizeof(int)*(c -> capacidade));
            if((c -> vetor) != NULL){
                for(i = 0; i < (a -> numero); i++){
                    (c -> vetor[i]) = (a -> vetor[i]);
                }
                for(j = 0; j < (b -> numero); j++){
                    for(k = 0; k < (a -> numero); k++){
                        if((b -> vetor[j]) == (c -> vetor[k])) igual = 1;
                    }
                    if(igual == 0){
                        (c -> vetor[i]) = (b -> vetor[j]);
                        i++;
                    } igual = 0;
                } c -> numero = i;
            }
        }
    }
}

void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a != NULL && b != NULL && c != NULL){
        int i = 0, j, k, igual = 0;
        if( (a -> numero) > 0 && (b -> numero) > 0){
            if((a -> numero) < (b -> numero)) (c -> capacidade) = (a -> numero);
            if((a -> numero) > (b -> numero)) (c -> capacidade) = (b -> numero);
            (c -> vetor) = (int*) realloc ((c -> vetor), sizeof(int)*(c -> capacidade));
            if((c -> vetor) != NULL){
                for(j = 0; j < (b -> numero); j++){
                    for(k = 0; k < (a -> numero); k++){
                        if((b -> vetor[j]) == (a -> vetor[k])) igual++;
                    }
                    if(igual != 0){
                        (c -> vetor[i]) = (b -> vetor[j]);
                        i++;
                        (c -> numero) = (i + 1);
                    } igual = 0;
                } 
            }
        }
    }
}

void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a != NULL && b != NULL && c != NULL){
        int i, j, k, igual = 0;
        if(((b -> numero) > 0) || (a -> numero) > 0){
            c -> capacidade = ((a -> numero) + (b -> numero));
            c -> vetor = (int*) realloc ((c -> vetor), sizeof(int)*(c -> capacidade));
            if((c -> vetor) != NULL){
                for(i = 0; i < (b -> numero); i++){
                    c -> vetor[i] = b -> vetor[i];
                }
                for(j = 0; j < (a -> numero); j++){
                    for(k = 0; k < (b -> numero); k++){
                        if((a -> vetor[j]) == (b -> vetor[k])) igual++;
                    }
                    if(igual == 0){
                        (c -> vetor[i]) = (a -> vetor[j]);
                        i++;
                    } igual = 0;
                } c -> numero = i;
            }
        }
    }
}

int conjunto_membro(elem_t x, conjunto_t *a){
    if (a != NULL){
        int j;
        for(j = 0; j < (a -> numero); j++){
            if( (a -> vetor[j]) == x) return 1;
        } return 0;
    } return 0;
}

int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    if (a != NULL){
        int j;
        for(j = 0; j < (a -> numero); j++){
            if( (a -> vetor[j]) == x) return 1;
        }
        if((a -> numero) < (a -> capacidade)){
            (a -> vetor[a -> numero]) = x;
            (a -> numero) += 1;
            return 1;
        }
        if((a -> numero) == (a -> capacidade)){
            ( a-> vetor) = (int*) realloc ((a -> vetor), sizeof(int) * ((a -> capacidade) + 1));
            (a -> vetor[(a -> numero)]) = x;
            (a -> numero) += 1;
            (a -> capacidade) += 1;
            return 1;
        } 
    } return 0;
}

void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    if (a != NULL){
        int j;
        for(j = 0; j < (a -> numero); j++){
            if( j != ((a -> numero) -1) && a -> vetor[j] == x) a -> vetor[j] = a -> vetor[j + 1];
            if( j == ((a -> numero) -1) && a -> vetor[j] == x) a -> vetor[j] = a -> vetor[j - 1];
        }
        for(j = 0; j < (a -> numero); j++){
            if( j != ((a -> numero) -1) && a -> vetor[j] == a -> vetor[j - 1] ) a -> vetor[j] = a -> vetor[j + 1];
        }
        if((a -> numero) < ((a -> capacidade) - 10) && (a -> capacidade) > 10){
            (a-> vetor) = (int*) realloc ((a -> vetor), sizeof(int) * ((a -> capacidade) - 10));
            (a -> capacidade) -= 10;
        }
        (a -> numero) -= 1;
    }
}
 
void conjunto_atribui(conjunto_t *a, conjunto_t *b){
    if (a != NULL && b != NULL){
        int j;
        (b -> numero) = (a -> numero);
        (b -> capacidade) = (a -> capacidade);
        if((b -> numero) > 0){
            (b -> vetor) = (int*) realloc ((b -> vetor), sizeof(int) * (b -> numero));
        }
        if((b -> vetor) != NULL){
            for(j = 0; j < (a -> numero); j++){
                    (b -> vetor[j]) = (a -> vetor[j]);
            }
        }
    }
}

int conjunto_igual(conjunto_t *a, conjunto_t *b){
    if (a != NULL && b != NULL){
        int igual = 0, j;
        if((a -> numero) == (b -> numero)){
            for(j = 0; j < (a -> numero); j++){
                if((a -> vetor[j]) == (b -> vetor[j])) igual++;
            } if (igual == (a -> numero)) return 1;
        } else return 0;
    } return 0;
}

elem_t conjunto_minimo(conjunto_t *a){
    if(a != NULL){
        if((a -> vetor) == NULL || (a -> numero) == 0) return ELEM_MAX;
        int j, i = (a -> vetor[0]);
        for(j = 0; j < (a -> numero); j++){
            if((a -> vetor[j]) < i) i = (a -> vetor[j]);
        } return i;
    } else return ELEM_MAX;
}

elem_t conjunto_maximo(conjunto_t *a){
    if(a != NULL){
        if((a -> vetor) == NULL || (a -> numero) == 0) return ELEM_MIN;
        int j, i = (a -> vetor[0]);
        for(j = 0; j < (a -> numero); j++){
            if((a -> vetor[j]) > i) i = (a -> vetor[j]);
        }return i;
    } else return ELEM_MIN;
}

void conjunto_imprime(conjunto_t *a){
    if(a != NULL){
        int i;
        if((a -> vetor) != NULL && (a -> numero) != 0){
            for(i = 0; i < (a -> numero); i++){
                if(i != ((a -> numero) - 1)) printf("%d ", (a -> vetor[i]));
                if(i == ((a->numero) - 1)) printf("%d\n", (a -> vetor[i]));
            }
        }
    }
}