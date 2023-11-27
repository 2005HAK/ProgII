#include "pilha.h"

struct no {
	int 		info;
	struct no	*ant;		
	struct no	*prx;
};

struct lista{
    no_t *cabeca;
    no_t *cauda;
};

lista_t **aloca_container(int qtd){
    lista_t **vetor = (lista_t**) malloc (sizeof(lista_t) * qtd);
    int i, x;
    if(!vetor) return NULL;
    for(i = 0; i < qtd; i++){
        vetor[i] = lista_cria();
        x = lista_insere_cauda(vetor[i], i);
    } return vetor;
}

lista_t* lista_cria	(){
    lista_t *ptr = (lista_t*) malloc (sizeof(lista_t));
    if(ptr != NULL){
        (ptr -> cabeca) = NULL;
        (ptr -> cauda) = NULL;
        return ptr;
    } else return NULL;
}

int	lista_insere_cauda	(lista_t *l, int dado){
    if(l != NULL){
        no_t *novo = (no_t*) malloc (sizeof(no_t));
        if(!novo) return -1;
        (novo -> info ) = dado;
        (novo -> prx) = NULL;
        (novo -> ant) = (l -> cauda);
        l -> cauda = novo;
        if(novo -> ant != NULL) (novo -> ant -> prx) = novo;
        if(l -> cabeca == NULL) l -> cabeca = novo;
        novo = NULL;
        return 1;
    } return -1;
}

int	lista_remove_cauda	(lista_t *l){
    if(l != NULL){
            if((l -> cauda) == NULL) return -1;
            no_t *aux = (l -> cauda);
            if((aux -> prx) == NULL && (aux -> ant) == NULL){
                (l -> cauda) = NULL;
                if((l -> cabeca) != NULL) (l -> cabeca) = NULL;
                free(aux);
                aux = NULL;
                return 1;
            }
            else{
                (l -> cauda) = (aux -> ant);
                if((l -> cauda -> prx) != NULL) (l -> cauda -> prx) = NULL;
                if((aux -> ant) != NULL) (aux -> ant) = NULL;
                if((aux -> prx) != NULL) (aux -> prx) = NULL;
                free(aux);
                aux = NULL;
                return 1;
            }
        } return -1;
}

int busca (lista_t **vetor, int a){
    int count = 0, i = 0, pos = 0;
    no_t *no;
    while(count == 0){
        no = vetor[i] -> cabeca;
        while(no -> prx != NULL){
            if(no -> info == a){
                pos = i;
                count = 1;
            } no = no -> prx;
        } 
        if(no -> info == a){
            pos = i;
            count = 1;
        } i++;
    } return pos;
}

void move_a_sobre_b (lista_t** vetor, int a, int b){
    int x, i = busca(vetor, a), j = busca(vetor, b);
    if(i == j || a == b) return;
    no_t *no = vetor[i] -> cauda;
    while(no -> info != a){
        x = lista_insere_cauda (vetor[no -> info], no -> info);
        x = lista_remove_cauda(vetor[i]);
        no = no -> ant;
    } x = lista_remove_cauda(vetor[i]);
    no = vetor[j] -> cauda;
    while(no -> info != b){
        x = lista_insere_cauda (vetor[no -> info], no -> info);
        x = lista_remove_cauda(vetor[j]);
    } lista_insere_cauda (vetor[j], a);
    no = NULL;
}

void move_a_topo_b (lista_t **vetor, int a, int b){
    int i = busca(vetor, a), j = busca(vetor, b), x;
    if(i == j || a == b) return;
    no_t *no = vetor[i] -> cauda;
    while(no -> info != a){
        x = lista_insere_cauda(vetor[no -> info], no -> info);
        x = lista_remove_cauda(vetor[i]);
        no = no -> ant;
    } x = lista_insere_cauda(vetor[j], no -> info);
    x = lista_remove_cauda(vetor[i]);
    no = NULL;
}

void empilha_a_sobre_b (lista_t **vetor, int a, int b){
    int i = busca(vetor, a), j = busca(vetor, b), x;
    if(i == j || a == b) return;
    no_t *no = vetor[j] -> cauda, *aux;
    while(no -> info != b){
        x = lista_insere_cauda (vetor[no -> info], no -> info);
        x = lista_remove_cauda(vetor[j]);
        no = no -> ant;
    }

    no = vetor[i] -> cabeca;
    while(no -> info != a) no = no -> prx;
    aux = no -> ant;
    if(aux != NULL) aux -> prx = NULL;
    if(no -> ant != NULL) no -> ant = NULL;
    vetor[j] -> cauda -> prx = no;
    no -> ant = vetor[j] -> cauda;
    vetor[j] -> cauda = vetor[i] -> cauda;
    vetor[i] -> cauda = aux;
    if(vetor[i] -> cauda == NULL) vetor[i] -> cabeca = NULL;
    
    if(aux != NULL) aux = NULL;
    no = NULL;
}

void empilha_a_topo_b (lista_t **vetor, int a, int b){
    if(a == b) return;
    int i = busca(vetor, a), j = busca(vetor, b);
    if(i == j) return;
    no_t *no = vetor[i] -> cabeca;
    while(no -> info != a) no = no -> prx;
    vetor[i] -> cauda = no -> ant;
    if(vetor[i] -> cauda == NULL) vetor[i] -> cabeca = NULL;
    if(no -> ant != NULL) no -> ant -> prx = NULL;
    if(no -> ant != NULL) no -> ant = NULL;

    vetor[j] -> cauda -> prx = no;
    no -> ant = vetor[j] -> cauda;
    while(no -> prx != NULL) no = no -> prx;
    vetor[j] -> cauda = no;

    no = NULL;
}

void sair (lista_t **vetor, int tamanho){
    no_t *no;
    int i, x;
    for(i = 0; i < tamanho; i++){
        if(vetor[i] -> cabeca != NULL){
            printf("%d: ", i);
            no = vetor[i] -> cabeca;
            while(no -> prx != NULL){
                printf("%d ", no -> info);
                no = no -> prx;
            } printf("%d\n", no -> info);
        } else printf("%d:\n", i);
    } printf("\n");

    for(i = tamanho - 1; i > -1; i--){
        no = vetor[i] -> cauda;
        if(no == NULL){
            free(vetor[i]);
        }
        else{
            while(no -> ant != NULL){
                x = lista_remove_cauda(vetor[i]);
                no = no -> ant;
            }
            vetor[i] -> cabeca = NULL;
            vetor[i] -> cauda = NULL;
            free(no);
            free(vetor[i]);
        }
    }
    no = NULL;
    free(vetor);
    if(vetor != NULL) vetor = NULL;
}