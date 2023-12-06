#include "abb_privado.h"
#include "abb.h"

/* Coloque abaixo as suas implementações */
abb_t *abb_cria(){
    abb_t *arvore = (abb_t*) malloc(sizeof(abb_t));
    arvore->raiz = NULL;
    return arvore;
}

void abb_destroi(abb_t **arv){
    if(arv != NULL){
        if(*arv != NULL){
            abb_destroi_rec((*arv)->raiz);
            free((*arv));
            *arv = NULL;
        }
        arv = NULL;
    }
}

int abb_insere(abb_t *arv, elem_t chave){
    if(arv != NULL){
        if(abb_busca(arv, chave) != 1){
            no_t *novoNo = (no_t *)malloc(sizeof(no_t));
            if(novoNo != NULL){
                novoNo->dir = NULL;
                novoNo->esq = NULL;
                novoNo->chave = chave;
                no_t *no = arv->raiz;
                if (no != NULL){
                    no_t *ant;
                    while (no != NULL){
                        ant = no;
                        if (chave > no->chave) no = no->dir;
                        else no = no->esq;
                    }
                    if (chave > ant->chave) ant->dir = novoNo;
                    else ant->esq = novoNo;
                }
                else arv->raiz = novoNo;
                return 1;
            }
            
        } return 0;
    } return -1;
}

int abb_remove(abb_t *arv, elem_t chave){
    if(arv != NULL){
        if(abb_busca(arv, chave) == 1){
            no_t *no = arv->raiz;
            no_t *ant = NULL;
            while (no->chave != chave){
                ant = no;
                if (chave > no->chave) no = no->dir;
                else no = no->esq;
            }
            if (no == arv->raiz && no->dir == NULL && no->esq == NULL){
                arv->raiz = NULL;
                free(no);
            } else if (no->dir == NULL && no->esq == NULL){
                if (no->chave > ant->chave) ant->dir = NULL;
                else ant->esq = NULL;
                free(no);
            } else if (no->dir != NULL && no->esq == NULL){
                if (no->chave > ant->chave) ant->dir = no->dir;
                else ant->esq = no->dir;
                free(no);
            } else if (no->dir == NULL && no->esq != NULL){
                if (no->chave > ant->chave) ant->dir = no->esq;
                else ant->esq = no->esq;
                free(no);
            } else if (no->dir != NULL && no->esq != NULL){
                int num;
                no_t *posAntecessor = no->esq;
                no_t *antesDoAntecessor = NULL;
                no_t *antecessor = NULL;
                for(num = ((no->chave) - 1); num > -99999; num--){
                    while (posAntecessor != NULL){
                        if (posAntecessor->chave == num){
                            antecessor = posAntecessor;
                            break;
                        } 
                        if (num > posAntecessor->chave){
                            antesDoAntecessor = posAntecessor;
                            posAntecessor = antesDoAntecessor->dir;
                        } else {
                            antesDoAntecessor = posAntecessor;
                            posAntecessor = antesDoAntecessor->esq;
                        }
                    }
                    if(antecessor != NULL){
                        if (antesDoAntecessor != NULL){
                            if (antecessor->esq != NULL){
                                antesDoAntecessor->dir = antecessor->esq;
                                no->chave = antecessor->chave;
                                free(antecessor);
                            } else {
                                no->chave = antecessor->chave;
                                free(antecessor);
                            }
                        } else {
                            if (antecessor->esq != NULL){
                                no->esq = antecessor->esq;
                                no->chave = antecessor->chave;
                                free(antecessor);
                            } else {
                                no->chave = antecessor->chave;
                                free(antecessor);
                            }
                        }
                        break;
                    }
                }
            }return 1;
        } return 0;
    } return -1;
}

int abb_busca(abb_t *arv, elem_t chave){
    if(arv != NULL){
        no_t *no = arv->raiz;
        while(no != NULL){
            if(no->chave == chave) return 1;
            if(chave > no->chave) no = no->dir;
            else no = no->esq;
        } return 0;
    } return -1;
}