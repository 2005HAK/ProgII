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
            l->cabeca = novoNo;
            l->tamanho++;
            if(l->tamanho == 1) l->cauda = novoNo;
            return 1;
        }
    } return -1;
}

int lista_insere_cauda(lista_t *l, tipo dado){

}

int lista_insere_posicao(lista_t *l, tipo dado, int pos){

}

int lista_remove_cabeca(lista_t *l, tipo *dado){

}

int lista_remove_cauda(lista_t *l, tipo *dado){

}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos){

}

int lista_remove_primeira(lista_t *l, tipo dado){

}

int lista_remove_todas(lista_t *l, tipo dado){

}

int lista_busca_info(lista_t *l, tipo dado){

}

int lista_frequencia_info(lista_t *l, tipo dado){

}

int lista_ordenada(lista_t *l){

}

int lista_insere_ordenado(lista_t *l, tipo dado){

}

int lista_compara(lista_t *l1, lista_t *l2){

}

int lista_reverte(lista_t *l){

}

lista_t *lista_cria_copia(lista_t *l){

}