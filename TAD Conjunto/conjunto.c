#include "conjunto_privado.h"

conjunto_t *conjunto_cria(void){
    conjunto_t *conjunto = (conjunto_t*) malloc(sizeof(conjunto_t));
    if(conjunto != NULL){
        conjunto -> capacidade = ELEMENTOS;
        conjunto_inicializa_vazio(conjunto);
        return conjunto;
    }
    return NULL;
}

void conjunto_destroi(conjunto_t **a){
    if((*a) != NULL){
        if((*a) -> vetor) free((*a) -> vetor);
        free(*a);
        *a = NULL;
    }
}

int conjunto_numero_elementos(conjunto_t *a){
    if(a != NULL) return a -> numero;
    return 0;
}

void conjunto_inicializa_vazio(conjunto_t *a){
    if(a != NULL){
        (a -> vetor) = (elem_t*) malloc(sizeof(int) * (a -> capacidade));
        (a -> numero) = 0;
    }
}
//salvar dados em outro vetor antes e mandar pro novo e dar free no antigo
int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    int i;
    if(a != NULL){
        for(i = 0; i < (a -> numero); i++) if(x == (a -> vetor)[i]) return 1;
        if(((a -> numero) + 1)  == (a -> capacidade)){
            (a -> vetor) = (elem_t*) realloc((a -> vetor), (a -> capacidade) + 1);
            (a -> capacidade) += 1;
        }
        (a -> vetor)[a -> numero] = x;
        (a -> numero) += 1;
    }
    return 0;
}

void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    int i;
    if(a != NULL){
        for(i = 0; i < (a -> numero); i++){
            if(x == (a -> vetor)[i]){
                for(i; i < (a -> numero); i++){
                    if((a -> vetor)[i + 1] != 0) (a -> vetor)[i] = (a -> vetor)[i + 1];
                    else (a -> vetor)[i] = 0;
                }
                (a -> numero) -= 1;
            }
        } 
        
    }
}
//tirar o espaço do ultimo elemento
void conjunto_imprime(conjunto_t *a){
    int i;
    if(a != NULL){
        if((a -> vetor) != NULL){
            for(i = 0; i < (a -> numero); i++){
                printf("%i ", (a -> vetor)[i]);
            }
        }
    }
}

void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    int i, j;
    if(a != NULL && b != NULL){
        c = (c == NULL) ? conjunto_cria() : c;
        for(i = 0; i < (a -> numero); i++){
            for(j = 0; j < (b -> numero); j++){
                if((a -> vetor)[i] == (b -> vetor)[j]){

                }
            }
        }
    }
}

void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){

}

void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    
}

int conjunto_membro(elem_t x, conjunto_t *a){

}

void conjunto_atribui(conjunto_t *a, conjunto_t *b){

}

int conjunto_igual(conjunto_t *a, conjunto_t *b){

}

elem_t conjunto_minimo(conjunto_t *a){

}

elem_t conjunto_maximo(conjunto_t *a){

}
