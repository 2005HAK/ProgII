#include "abb_privado.h"

int main(){
    // Criação da árvore
    abb_t *arv = abb_cria();

    // Inserção de elementos
    abb_insere(arv, 6);
    abb_insere(arv, 9);
    abb_insere(arv, 20);
    abb_insere(arv, 5);
    abb_insere(arv, 2);
    abb_insere(arv, 3);
    abb_insere(arv, 7);
    abb_insere(arv, 24);
    abb_insere(arv, 17);
    abb_insere(arv, 9);
    abb_insere(arv, 27);
    abb_insere(arv, 30);
    abb_insere(arv, 16);
    abb_insere(arv, 23);
    abb_insere(arv, 47);
    abb_insere(arv, 52);

    // Remoção de elementos
    abb_remove(arv, 9);
    abb_remove(arv, 20);
    abb_remove(arv, 6);
    abb_remove(arv, 7);
    abb_remove(arv, 100);  // Tentativa de remover elemento inexistente

    // Inserção após remoção
    abb_insere(arv, 19);
    abb_insere(arv, 3);

    // Tentativas de inserir elementos duplicados
    abb_insere(arv, 30);
    abb_insere(arv, 17);

    // Tentativa de remover elemento inexistente
    abb_remove(arv, 13);
    abb_destroi(&arv);
    return 0;
}