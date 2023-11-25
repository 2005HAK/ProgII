#include "pilha.h"

// Estrutura de nó duplamente encadeado
struct no
{
    tipo info;      // Informação (dado) armazenada no nó
    struct no *ant; // Ponteiro para o nó anterior
    struct no *prx; // Ponteiro para o próximo nó
};

// Estrutura de lista duplamente encadeada com nós
struct lista
{
    no_t *cabeca; // Ponteiro para a cabeça da lista (primeiro)
    no_t *cauda;  // Ponteiro para a cauda da lista (último)
    int tamanho;  // Tamanho atual da lista
};

lista_t **criaContainers(int tam){
    int i;
    lista_t **containers = (lista_t**) malloc(sizeof(lista_t) * tam);
    if(containers != NULL){
        for (i = 0; i < tam; i++){
            containers[i] = lista_cria();
            lista_insere_cauda(containers[i], i);
        }
    } return containers;
}

lista_t *lista_cria(){
    lista_t *novaLista = (lista_t *) malloc(sizeof(lista_t));
    if(novaLista != NULL){
        novaLista->tamanho = 0;
        novaLista->cabeca = NULL;
        novaLista->cauda = NULL;
        return novaLista;
    } return NULL;
}

void lista_destroi(lista_t **l){
    if(l != NULL){
        if((*l) != NULL){
            no_t *atual = (*l)->cabeca;
            no_t *prox;
            while(atual != NULL){
                prox = atual->prx;
                free(atual);
                atual = prox;
            }
            (*l)->cabeca = NULL;
            (*l)->cauda = NULL;
            free(*l);
            *l = NULL;
        }
        l = NULL;
    }
}

int lista_inicializada(lista_t *l){
    if(l != NULL) if(l->tamanho >= 0) return 1;
    return 0;
}

int lista_info_cauda(lista_t *l, int *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            *dado = l->cauda->info;
            return 1;
        } return 0;
    } return -1;
}

int lista_insere_cauda(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        no_t *novoNo = (no_t*) malloc(sizeof(no_t));
        if(novoNo != NULL){
            novoNo->info = dado;
            novoNo->prx = NULL;
            novoNo->ant = l->cauda;
            if(l->cauda != NULL) l->cauda->prx = novoNo;
            l->cauda = novoNo;
            l->tamanho++;
            if(l->tamanho == 1) l->cabeca = novoNo;
            return 1;
        }
    } return -1;
}

int lista_remove_cauda(lista_t *l, tipo *dado){
    if (dado != NULL && lista_inicializada(l) == 1){ 
        if(l->tamanho != 0){
            if(l->cauda != NULL){
                no_t *caudaNova = l->cauda->ant;
                *dado = l->cauda->info;
                l->cauda->ant = NULL;
                free(l->cauda);
                l->cauda = caudaNova;
                if(l->cauda != NULL) l->cauda->prx = NULL;
                else l->cabeca = NULL;
                caudaNova = NULL;
                l->tamanho--;
                return 1;
            } else return -1;
        } return 0;
    } return -1;
}

int lista_busca_info(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            int i;
            no_t *atual = l->cabeca;
            for (i = 0; i < l->tamanho; i++){
                if (atual->info == dado){
                    return i;
                }
                atual = atual->prx;
            }
        }
    } return -1;
}

void lista_imprime(lista_t *l){
    if (lista_inicializada(l) == 1){ 
        int i;
        no_t *no = l->cabeca;
        for(i = 0; i < l->tamanho; i++){
            printf("%i ", no->info);
            no = no->prx;
        }
        printf("\n");
    }
}

void moveAAboveB (lista_t **c, int a, int b, int tam){
    int pos = 0, listaB = 0, valor = 0, i;
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], b);
        if(pos != -1){
            listaB = i;
            while(c[i]->tamanho - 1 > pos){
                lista_insere_cauda(c[c[i]->cauda->info], c[i]->cauda->info);
                lista_remove_cauda(c[i], &valor);
            }
            break;
        }  
    }

    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], a);
        if(pos != -1){
            int tamanho = c[i]->tamanho;
            while(tamanho > pos + 1){
                lista_insere_cauda(c[c[i]->cauda->info], c[i]->cauda->info);
                lista_remove_cauda(c[i], &valor);
                tamanho--;
            }
            lista_remove_cauda(c[i], &valor);
            lista_insere_cauda(c[listaB], a);
            break;
        }
    }

}

void moveAUpB (lista_t **c, int a, int b, int tam){
    int valor = 0, i, pos = 0, listaB = 0, tamanho;
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], b);
        if(pos != -1){
            listaB = i;
            break;
        }  
    }
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], a);
        if(pos != -1){
            tamanho = c[i]->tamanho;
            while(tamanho > pos + 1){
                lista_insere_cauda(c[c[i]->cauda->info], c[i]->cauda->info);
                lista_remove_cauda(c[i], &valor);
                tamanho--;
            }
            lista_remove_cauda(c[i], &valor);
            lista_insere_cauda(c[listaB], a);
            break;
        }
    }
}

void stackingAAboveB (lista_t **c, int a, int b, int tam){
    int pos = 0, listaB = 0, valor = 0, i, tamanho, j;
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], b);
        if(pos != -1){
            listaB = i;
            while(c[i]->tamanho - 1 > pos){
                lista_insere_cauda(c[c[i]->cauda->info], c[i]->cauda->info);
                lista_remove_cauda(c[i], &valor);
            }
            break;
        }  
    }
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], a);
        if(pos != -1){
            no_t *atual = c[i]->cabeca;
            for (j = 0; j < (c[i]->tamanho - 1); j++){
                if (atual->info == a){
                    break;
                }
                atual = atual->prx;
            }
            tamanho = c[i]->tamanho - pos; 
            no_t *cauda = c[i]->cauda;
            if(atual->ant != NULL) atual->ant->prx = NULL;
            c[i]->cauda = atual->ant;
            c[i]->tamanho = pos;
            if(c[i]->tamanho == 0) c[i]->cabeca = NULL;
            atual->ant = c[listaB]->cauda;
            if(c[listaB]->cauda != NULL) c[listaB]->cauda->prx = atual;
            c[listaB]->cauda = cauda;
            c[listaB]->tamanho += tamanho;
        }
    }
}

void stackingAUpB (lista_t **c, int a, int b, int tam){
    int pos = 0, listaB = 0, valor = 0, i, tamanho, j;
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], b);
        if(pos != -1){
            listaB = i;
            break;
        }  
    }
    for(i = 0; i < tam; i ++){
        pos = lista_busca_info(c[i], a);
        if(pos != -1){
            if(i != listaB){
                no_t *atual = c[i]->cabeca;
                for (j = 0; j < (c[i]->tamanho - 1); j++){
                    if (atual->info == a){
                        break;
                    }
                    atual = atual->prx;
                }
                tamanho = c[i]->tamanho - pos;
                no_t *cauda = c[i]->cauda;
                if (atual->ant != NULL) atual->ant->prx = NULL;
                c[i]->cauda = atual->ant;
                c[i]->tamanho = pos;
                if (c[i]->tamanho == 0) c[i]->cabeca = NULL;
                atual->ant = c[listaB]->cauda;
                if (c[listaB]->cauda != NULL) c[listaB]->cauda->prx = atual;
                c[listaB]->cauda = cauda;
                c[listaB]->tamanho += tamanho;
            }
            
        }
    }
}

void exitContainers (lista_t **c, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%i: ", i);
        lista_imprime(c[i]);
        lista_destroi(&c[i]);
    }
}