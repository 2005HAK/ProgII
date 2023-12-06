#include "abb_privado.h"

int main(){
        // Criação da árvore
    abb_t *arv = abb_cria();

    // Tentativa de remoção em uma árvore vazia
    abb_remove(arv, 5);

    // Inserções
    abb_insere(arv, 10);
    abb_insere(arv, 5);
    abb_insere(arv, 15);
    abb_insere(arv, 7);
    abb_insere(arv, 12);
    abb_insere(arv, 20);
    abb_insere(arv, 7);  // Inserção repetida

    // Tentativa de remoção de um elemento não presente
    abb_remove(arv, 8);

    // Remoções
    abb_remove(arv, 15);
    abb_remove(arv, 10);
    abb_remove(arv, 7);
    abb_remove(arv, 5);

    // Tentativa de remoção em uma árvore vazia
    abb_remove(arv, 12);

    // Destroi a árvore
    abb_destroi(&arv);

    // Tentativa de remoção em uma árvore vazia
    abb_remove(arv, 5);

    // Inserções
    abb_insere(arv, 10);
    abb_insere(arv, 5);
    abb_insere(arv, 15);
    abb_insere(arv, 7);
    abb_insere(arv, 12);
    abb_insere(arv, 20);
    abb_insere(arv, 7);  // Inserção repetida

    // Tentativa de remoção de um elemento não presente
    abb_remove(arv, 8);

    // Remoções
    abb_remove(arv, 15);
    abb_remove(arv, 10);
    abb_remove(arv, 7);
    abb_remove(arv, 5);

    // Tentativa de remoção em uma árvore vazia
    abb_remove(arv, 12);

    // Tentativa de busca em uma árvore vazia
    abb_busca(arv, 20);

    // Tentativa de inserção em uma árvore destruída
    abb_destroi(&arv);
    abb_insere(arv, 30);

    // Tentativa de remoção em uma árvore destruída
    abb_remove(arv, 12);

    

    // Caso 2: Acesso a um nó desalocado (memória liberada)
    abb_t *arv2 = abb_cria();
    abb_insere(arv2, 5);
    abb_remove(arv2, 5);
    abb_busca(arv2, 5);  // Tentando buscar em um nó desalocado
    abb_destroi(&arv2);

    // Caso 3: Tentativa de inserir em uma árvore destruída
    abb_t *arv3 = abb_cria();
    abb_destroi(&arv3);
    abb_insere(arv3, 8);  // Tentando inserir em uma árvore destruída

    // Caso 4: Uso de uma árvore destruída
    abb_t *arv4 = abb_cria();
    abb_destroi(&arv4);
    abb_remove(arv4, 10);  // Tentando remover de uma árvore destruída

    // Caso 5: Uso de uma árvore desalocada (memória liberada)
    abb_t *arv5 = abb_cria();
    abb_destroi(&arv5);
    abb_busca(arv5, 10);  // Tentando buscar em uma árvore desalocada

    // Caso 1: Acesso a um ponteiro não inicializado (nulo)
    abb_t *arv1 = NULL;
    abb_insere(arv1, 10);  // Tentando inserir em um ponteiro nulo
    // Caso 1: Tentativa de remover de uma árvore vazia
    abb_remove(arv1, 10);  // Tentando remover de uma árvore vazia
    abb_destroi(&arv1);

    // Caso 2: Tentativa de remoção de um nó nulo
    abb_remove(arv2, 10);  // Tentando remover de uma árvore com raiz nula
    abb_destroi(&arv2);

    // Caso 3: Manipulação indevida de ponteiro após liberação
    abb_insere(arv3, 5);
    abb_destroi(&arv3);
    abb_remove(arv3, 5);  // Tentando remover de uma árvore desalocada

    // Caso 4: Uso indevido de ponteiro não alocado
    abb_remove(arv4, 10);  // Tentando remover de uma árvore com raiz nula
    abb_destroi(&arv4);

    // Caso 5: Acesso indevido a posição inválida da memória
    abb_insere(arv5, 5);
    abb_remove(arv5, 5);
    abb_destroi(&arv5);

    // Caso 6: Tentativa de busca em uma árvore nula
    abb_t *arv6 = NULL;
    abb_busca(arv6, 10);  // Tentando buscar em um ponteiro nulo

    return 0;
}