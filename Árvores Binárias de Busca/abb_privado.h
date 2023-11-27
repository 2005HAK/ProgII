#ifndef _abb_privado_h_
#define _abb_privado_h_

#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Definição da struct no
 *
 * Nó da Árvore Binária de Busca (ABB). Possui uma chave (elemento)
 * e dois ponteiros: um para seu filho esquerdo (esq) e outro para
 * seu filho direito (dir). Não altere a estrutura fornecida.
 *
 */
struct no{
    struct no *esq;
    struct no *dir;
    elem_t chave;
};

/**
 * Definição da struct abb
 * Estrutura da Árvore Binária de Busca (ABB). Contém um ponteiro
 * para a raiz da árvore. Não altere a estrutura fornecida.
 *
 */
struct abb{
    no_t *raiz;
};

/**
 * Definição de funções privadas do TAD Árvore Binária de Busca
 * 		Funções definidas neste arquivo não estão acessíveis
 * 		externamente ao TAD. Estas funções podem porém, ser
 * 		acessadas internamente ao TAD, por outras funções.
 */

/**
 * @brief Esta função faz a destruição de fato da ABB. Ela é
 * chamada a partir da função abb_destroi (que é pública).
 * Note que esta função recebe a raiz da ABB como parâmetro.
 * Esta função deve ser implementada de forma *recursiva*.
 *
 * @param n a raiz da ABB que será destruída.
 */
void abb_destroi_rec(no_t *n);

#endif
