#ifndef _abb_h_
#define _abb_h_

/**
 * Árvore Binária de Busca (ABB)
 *
 * 		Implementa o TAD Árvore Binária de Busca
 *
 */

/* Inclusão de bibliotecas necessárias */
#include <stdio.h>
#include <stdlib.h>

/* Definição do tipo dos elementos armazenados na ABB */
typedef int elem_t;

/* Definição dos tipos nó e árvore binária de busca */
typedef struct no no_t;
typedef struct abb abb_t;

/**
 * @brief Cria uma ABB
 * @details Cria uma ABB vazia.
 * @return Retorna um ponteiro para a ABB criada.
 */
abb_t *abb_cria();

/**
 * @brief Destrói uma ABB
 * @details Destrói uma ABB, liberando a memória de todos seus nós
 * e da própria estrutura da árvore. Ao final, o ponteiro da ABB
 * passado como parâmetro (por referência) deve apontar para NULL.
 *
 * @param arv a ABB a ser destruída
 */
void abb_destroi(abb_t **arv);

/**
 * @brief Insere uma chave na ABB
 * @details Insere a chave passada como parâmetro na ABB. Se a cha-
 * ve já está presente na árvore a inserção não deve ocorrer.
 *
 * @param arv a ABB na qual a inserção deve ser realizada.
 * @param chave a chave a ser inserida
 *
 * @return Retorna -1 caso a árvore não esteja inicializada. Se for
 * possível realizar a inserção retorna 1. Caso a chave já esteja
 * presente na árvore, a inserção não ocorre e retorna 0.
 */
int abb_insere(abb_t *arv, elem_t chave);

/**
 * @brief Remove um elemento (chave) da ABB
 * @details Remove um elemento da ABB (caso exista). Após a remover
 * a ABB deve continuar válida.
 *
 * @param arv a ABB na qual a remoção deve ser realizada.
 * @param chave chave que deve ser removida
 *
 * @return Retorna -1 caso a árvore não esteja inicializada. Se o
 * valor (chave) não for encontrado retorna 0. Caso consiga reali-
 * zar a remoção corretamente retorna 1.
 */
int abb_remove(abb_t *arv, elem_t chave);

/**
 * @brief Busca uma chave na ABB
 * @details Busca/verifica se uma chave está contida na ABB
 *
 * @param arv a ABB na qual a busca será realizada
 * @param chave a chave que deve ser buscada
 *
 * @return Retorna -1 caso a ABB não esteja inicializada. Retorna
 * o valor 1 caso encontrar e 0 caso não encontrar.
 */
int abb_busca(abb_t *arv, elem_t chave);

#endif
