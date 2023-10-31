#include "lista.h"

/**
 * arquivo lista.c
 *
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso
 * contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de lista
struct lista
{
    tipo *dados;    // Vetor que armazena os dados
    int capacidade; // Capacidade de armazenamento da lista
    int tamanho;    // Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

lista_t *lista_cria(int capacidade){
    if(capacidade > 0){
        lista_t *lista = (lista_t*) malloc (sizeof(lista_t));
        if(lista != NULL){
            (lista->dados) = (int*) malloc(sizeof(int) * capacidade);
            if((lista->dados) != NULL){
                (lista->capacidade) = capacidade;
                (lista->tamanho) = 0; 
            } else {
                free(lista);
                lista = NULL;
            }
            return lista;
        }return NULL;
    }return NULL;
}

void lista_destroi(lista_t **l){
    if(l != NULL){
        if((*l) != NULL){
            if(((*l)->dados) != NULL){
                free((*l)->dados);
                ((*l)->dados) = NULL;
            }
            free(*l);
            (*l) = NULL;  
        }
        l = NULL;
    }
}

int lista_inicializada(lista_t *l){
    if(l != NULL) if((l->dados) != NULL) if((l->capacidade) > 0 && (l->tamanho) >= 0) return 1;
    return 0;
}

int lista_tamanho(lista_t *l){
    if(lista_inicializada(l) == 1) return (l->tamanho);
    return -1;
}

int lista_capacidade(lista_t *l){
    if(lista_inicializada(l) == 1) return (l->capacidade);
    return -1;
}

int lista_cheia(lista_t *l){
    if(lista_inicializada(l) == 1){
        if((l->capacidade) == (l->tamanho)) return 1;
        return 0;
    } return -1;
}

int lista_info_cabeca(lista_t *l, int *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if((l->tamanho) != 0){
            *dado = (l->dados)[0];
            return 1;
        } return 0;
    } return -1;
}

int lista_info_cauda(lista_t *l, int *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if((l->tamanho) != 0){
            *dado = (l->dados)[(l->tamanho) - 1];
            return 1;
        } return 0;
    } return -1;
}

int lista_info_posicao(lista_t *l, int *dado, int pos){
    if(dado != NULL && lista_inicializada(l) == 1){
        if(pos >= 0 && pos < (l->tamanho) && (l->tamanho) != 0){
            *dado = (l->dados)[pos];
            return 1;
        } return 0;        
    } return -1;
}

int lista_insere_cabeca(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 0){
            int i;
            for(i = (l->tamanho); i > 0; i--) (l->dados)[i] = (l->dados)[i - 1];
            (l->dados)[0] = dado;
            (l->tamanho)++;
            return 1;
        }
    } return -1;
}

int lista_insere_cauda(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 0){
            (l->dados)[l->tamanho] = dado;
            (l->tamanho)++;
            return 1;
        }
    } return -1;
}

int lista_insere_posicao(lista_t *l, tipo dado, int pos){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 0){
            if (pos >= 0 && pos < (l->tamanho)){
                int i;
                for(i = (l->tamanho); i > pos; i--) (l->dados)[i] = (l->dados)[i - 1];
                (l->dados)[pos] = dado;
                (l->tamanho)++;
                return 1;
            } return 0;
        }
    } return -1;
}

int lista_remove_cabeca(lista_t *l, tipo *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if((l->tamanho) != 0){
            int i;
            dado = (l->dados)[0];
            for(i = 0; i < ((l->tamanho) - 1); i++) (l->dados)[i] = (l->dados)[i + 1];
            (l->tamanho)--;
        } return 0;
    } return -1;
}

int lista_remove_cauda(lista_t *l, tipo *dado){
    if(dado != NULL && lista_inicializada(l) == 1){
        if((l->tamanho) != 0){
            dado = (l->dados)[(l->tamanho) - 1];
            (l->tamanho)--;
            return 1;
        } return 0;
    } return -1;
}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos){
    if(dado != NULL && lista_inicializada(l) == 1){
        if((l->tamanho) != 0 && pos >= 0 && pos < (l->tamanho)){
            int i;
            *dado = (l->dados)[pos];
            for(i = pos; i < ((l->dados) - 1); i++) (l->dados)[i] = (l->dados)[i + 1]; 
            (l->tamanho)--;
            return 1;
        } return 0;
    } return -1;
}

int lista_remove_primeira(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        int i, remov;
        for(i = 0; i < (l->tamanho); i++){
            if((l->dados)[i] == dado){
                remov = i;
                for(i; i < ((l->tamanho) - 1); i++){
                    (l->dados)[i] = (l->dados)[i + 1];
                }
                return remov;
            } return -2;
        }
    } return -1;
}

int lista_remove_todas(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        int *vetor = (int*) malloc (sizeof(int)*(l->tamanho));
        if(vetor != NULL){
            int i, j = 0;
            for(i = 0; i < (l->tamanho); i++){
                if((l->dados)[i] != dado){
                    vetor[j] = (l->dados)[i];
                    j++;
                } 
            }
            for(i = 0; i < (l->tamanho); i++){
                (l->dados)[i] = vetor[i];
            }
            (l->tamanho) -= j;
            free(vetor);
            vetor = NULL;
            return j;
        }
    } return -1;
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