#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    int valor;
    noLista *prox;
}noLista;

typedef struct lista {
    int tamanho;
    noLista *primeiro;
}lista;

lista * listaCria(){
    lista *l = (lista*) malloc(sizeof(lista));
    l->tamanho = 0;
    l->primeiro = NULL;
    return l;
}

int listaInsereCabeca(lista *l, int elem){
    if(l != NULL){
        noLista *novo = (noLista*) malloc(sizeof(noLista));
        if(novo != NULL){
            novo->valor = elem;
            novo->prox = l->primeiro;
            l->tamanho++;
            l->primeiro = novo;
        }
        return -1;
    }
    return -1;
}

void listaImprime(lista *l){
    if(!l) printf("Lista = !\n");
    else{
        printf("Lista  = <");
        
        noLista *aux = l->primeiro;
        
        while(aux){
            printf("%d", aux->valor);
            aux = aux->prox;
        }
        printf("<\n");
    }
}

int insereFinal(lista *l, int elem){
    if(l != NULL){
        noLista *novo = (noLista*) malloc(sizeof(noLista));
        novo->valor = elem;
        novo->prox = NULL;

        noLista *aux = l->primeiro;
        while(aux && aux->prox) aux = aux->prox;

        if(!aux) l->primeiro = novo;
        else aux->prox = novo;

        l->tamanho++;
        return 1;
    }
    return -1;
}

int removePrimeiro(lista *l, int *elem){
    if(!l || !l->primeiro) return -1;
    noLista *aux = l->primeiro;
    l->primeiro = l->primeiro->prox;
    *elem = aux->valor;
    free(aux);
    l->tamanho--;
    return 1;
}

int removePrimeiraOcorrencia(lista *l, int elem){
    if(!l || !l->primeiro) return -1;
    noLista *atual = l->primeiro, *anterior = NULL;

    while(atual != NULL && atual->valor != elem){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return 1;

    if (anterior == NULL){
        int rem;
        removePrimeiraOcorrencia(l, &rem);
    }else{
        anterior->prox = atual->prox;
        free(atual);
        l->tamanho--;
    }
    
    return 1;
}