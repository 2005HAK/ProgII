#include "lista.h"

/**
 * arquivo lista.c
 *
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

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

// Coloque a partir daqui a implementação das funções

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
        }
        l = NULL;
    }
}

int lista_inicializada(lista_t *l){
    if(l != NULL){
        if(l->tamanho >= 0) return 1;
        lista_destroi(&l);
    } return 0;
}

int lista_tamanho(lista_t *l){
    if(lista_inicializada(l) == 1) return l->tamanho;
    return -1;
}

int lista_info_cabeca(lista_t *l, int *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            *dado = l->cabeca->info;
            return 1;
        } return 0;
    } return -1;
}

int lista_info_cauda(lista_t *l, int *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            *dado = l->cauda->info;
            return 1;
        } return 0;
    } return -1;
}

int lista_info_posicao(lista_t *l, int *dado, int pos){
    if(dado != NULL && lista_inicializada(l) == 1){
        if(l->tamanho != 0 && pos >= 0 && pos < l->tamanho){
            int i;
            no_t *atual = l->cabeca;
            for(i = 0; i < l->tamanho; i++){
                if(pos == i) break;
                atual = atual->prx;
            }
            *dado = atual->info;
            return 1;
        } return 0;
    } return -1;
}

int lista_insere_cabeca(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        no_t *novoNo = (no_t*) malloc(sizeof(no_t));
        if(novoNo != NULL){
            novoNo->info = dado;
            novoNo->prx = l->cabeca;
            novoNo->ant = NULL;
            if(l->cabeca != NULL) l->cabeca->ant = novoNo;
            l->cabeca = novoNo;
            l->tamanho++;
            if(l->tamanho == 1) l->cauda = novoNo;
            return 1;
        }
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

int lista_insere_posicao(lista_t *l, tipo dado, int pos){
    if (lista_inicializada(l) == 1){ 
        if(pos >= 0 && pos <= l->tamanho){
            if(pos == 0) return lista_insere_cabeca(l, dado);
            else if (pos == l->tamanho) return lista_insere_cauda(l, dado);
            else{
                no_t *novoNo = (no_t *)malloc(sizeof(no_t));
                if (novoNo != NULL){
                    int i;
                    no_t *atual = l->cabeca;
                    for (i = 0; i < l->tamanho; i++){
                        if (pos == i) break;
                        atual = atual->prx;
                    }
                    novoNo->prx = atual;
                    novoNo->ant = atual->ant;
                    atual->ant->prx = novoNo;
                    atual->ant = novoNo;
                    novoNo->info = dado;
                    l->tamanho++;
                } else return -1;
            } return 1;
        } return 0;
    } return -1;
}

int lista_remove_cabeca(lista_t *l, tipo *dado){
    if (dado != NULL && lista_inicializada(l) == 1){ 
        if(l->tamanho != 0){
            no_t *cabecaAntiga = l->cabeca;
            *dado = cabecaAntiga->info;
            l->cabeca = l->cabeca->prx;
            l->cabeca->ant = NULL;
            cabecaAntiga->prx = NULL;
            free(cabecaAntiga);
            cabecaAntiga = NULL;
            l->tamanho--;
            return 1;
        } return 0;
    } return -1;
}

int lista_remove_cauda(lista_t *l, tipo *dado){
    if (dado != NULL && lista_inicializada(l) == 1){ 
        if(l->tamanho != 0){
            no_t *caudaAntiga = l->cauda;
            *dado = caudaAntiga->info;
            l->cauda = l->cauda->ant;
            l->cauda->prx = NULL;
            caudaAntiga->ant = NULL;
            free(caudaAntiga);
            caudaAntiga = NULL;
            l->tamanho--;
            return 1;
        } return 0;
    } return -1;
}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos){
    if (dado != NULL && lista_inicializada(l) == 1){ 
        if(l->tamanho != 0 && pos >=0 && pos < l->tamanho){
            if (pos == 0) lista_remove_cabeca(l, dado);
            else if (pos == l->tamanho - 1) lista_remove_cauda(l, dado);
            else {
                int i;
                no_t *atual = l->cabeca;
                for (i = 0; i < l->tamanho; i++){
                    if (pos == i) break;
                    atual = atual->prx;
                }
                *dado = atual->info;
                atual->ant->prx = atual->prx;
                atual->prx->ant = atual->ant;
                atual->prx = NULL;
                atual->ant = NULL;
                free(atual);
                atual = NULL;
                l->tamanho--;
            } return 1;
        } return 0;
    } return -1;
}

int lista_remove_primeira(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            int i;
            no_t *atual = l->cabeca;
            for (i = 0; i < l->tamanho; i++){
                if (atual->info == dado){
                    int dado;
                    lista_remove_posicao(l, &dado, i);
                    return i;
                }
                atual = atual->prx;
            }
        } return -2;
    } return -1;
}

int lista_remove_todas(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        int retorno = lista_remove_primeira(l, dado), quantidadeRemocoes = 0;
        while(retorno != -2){
            quantidadeRemocoes++;
            retorno = lista_remove_primeira(l, dado);
        }
        return quantidadeRemocoes;
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

int lista_frequencia_info(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        int freq = 0;
        if(l->tamanho != 0){
            int i;
            no_t *atual = l->cabeca;
            for (i = 0; i < l->tamanho; i++){
                if (atual->info == dado){
                    freq++;
                }
                atual = atual->prx;
            }
        } return freq;
    } return -1;
}

int lista_ordenada(lista_t *l){
    if (lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            int i;
            no_t *atual = (l->cabeca);
            for (i = 0; i < (l->tamanho - 1); i++){
                if(atual->info > atual->prx->info) return 0;
                atual = atual->prx;
            }
        } return 1;
    } return -1;
}

int lista_insere_ordenado(lista_t *l, tipo dado){
    if (lista_inicializada(l) == 1){
        if(l->tamanho != 0){
            int i;
            no_t *atual = (l->cabeca);
            for (i = 0; i < l->tamanho; i++){
                if(dado < atual->info){
                    lista_insere_posicao(l, dado, i);
                    break;
                } else if (i == (l->tamanho - 1)){
                    lista_insere_posicao(l, dado, l->tamanho);
                    break;
                } 
                atual = atual->prx;
            }
        } else lista_insere_cabeca(l, dado);
        return 1;
    } return -1;
}

int lista_compara(lista_t *l1, lista_t *l2){
    if(lista_inicializada(l1) == 1 && lista_inicializada(l2) == 1){
        if(l1->tamanho == l2->tamanho){
            int i;
            no_t *atual1 = (l1->cabeca);
            no_t *atual2 = (l2->cabeca);
            for (i = 0; i < l1->tamanho; i++){
                if(atual1->info != atual2->info) return 0;
                atual1 = atual1->prx;
                atual2 = atual2->prx;
            }
            return 1;
        } return 0;
    } else if (lista_inicializada(l1) == 0 && lista_inicializada(l2) == 0) return 1;
    return 0;
}

int lista_reverte(lista_t *l){
    if (lista_inicializada(l) == 1){
        int i;
        no_t *atual = l->cabeca;
        l->cabeca = l->cauda;
        l->cauda = atual;
        for(i = 0; i < l->tamanho; i++){
            no_t *ant = atual->ant;
            atual->ant = atual->prx;
            atual->prx = ant;
            atual = atual->ant;
        }
        return 1;
    } return -1;
}

lista_t *lista_cria_copia(lista_t *l){
    if(lista_inicializada(l) == 1){
        lista_t *copiaLista = lista_cria();
        if(copiaLista != NULL){
            int i;
            no_t *atual = l->cabeca;
            for(i = 0; i < l->tamanho; i++){
                lista_insere_cauda(copiaLista, atual->info);
                atual = atual->prx;
            }
            return copiaLista;
        }
    } return NULL; 
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