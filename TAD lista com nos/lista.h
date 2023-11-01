/**
 * Lista Duplamente Encadeada
 *
 * 		Implementa uma lista duplamente encadeada com nós e ponteiros.
 *
 * 		Não modifique o código fornecido neste arquivo. Você pode incluir
 * 		declarações de funções adicionais, caso desejar, mas não modifique
 * 		as declarações de funções já existentes.
 */

#ifndef _lista_de_
#define _lista_de_

/**
 * Inclusão de bibliotecas
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Typedefs para renomear os tipos definidos pelas estruturas e definir o tipo
 * de dado que será efetivamente armazenado na lista. Para avaliar seu código
 * deixe o tipo de dados como int (inteiro), caso contrário não irá funcionar.
 */

typedef struct no no_t;
typedef struct lista lista_t;
typedef int tipo;

/**
 * @brief Cria e inicializa uma estrutura de lista, retornando seu endereço
 *
 * @details Aloca memória para uma estrutura de lista duplamente encadeada e re-
 * torna seu endereço (ponteiro). Inicialmente a lista criada é vazia, ou seja,
 * não contém nenhum elemento. Caso não seja possível realizar a alocação a fun-
 * ção deve retornar NULL.
 *
 * @return Ponteiro para a lista inicializada. Caso falhe, retorna NULL.
 */
lista_t *lista_cria();

/**
 * @brief Destrói uma lista duplamente encadeada.
 *
 * @details Destrói uma lista duplamente encadeada, desalocando a memória de to-
 * dos os nós que compõem a lista, assim como a memória de sua estrutura. Ao fi-
 * nal, o ponteiro da lista é setado para nulo (NULL) --- por este motivo o ponteiro
 * da lista é passado por referência para a função (ponteiro duplo).
 *
 * @param l Ponteiro para o ponteiro da lista (l). Ou seja, a lista passada por
 * referência.
 */
void lista_destroi(lista_t **l);

/**
 * @brief Verifica se a lista esta propriamente inicializada.
 * @details Verifica se a lista é diferente de NULL, ou seja, se foi propriamente
 * inicializada.
 *
 * @param l A lista a ser verificada
 * @return Retorna 1 se a lista não é nula, e 0 se a lista for nula.
 */
int lista_inicializada(lista_t *l);

/**
 * @brief Retorna o tamanho da lista (seu número de elementos).
 * @details Retorna a quantidade de elementos armazenados na lista.
 *
 * @param l A lista para qual o tamanho deve ser determinado.
 * @return Retorna o tamanho da lista, caso ela seja válida. Se a lista for in-
 * válida, retorna -1.
 */
int lista_tamanho(lista_t *l);

/**
 * @brief Obtém o dado armazenado na cabeça da lista
 * @details Obtém, se possível, o dado armazenado na cabeça da lista
 *
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cabeça
 *
 * @return Retorna 1, caso seja possível obter o dado da cabeça da lista que,
 * após a chamada da função estará armazenado em dado. Caso a lista seja inválida 
 * retorna -1. Caso seja vazia, retorna 0. Caso dado seja nulo retorna -1.
 */
int lista_info_cabeca(lista_t *l, int *dado);

/**
 * @brief Obtém o dado armazenado na cauda da lista
 * @details Obtém, se possível, o dado armazenado na cauda da lista
 *
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cauda
 *
 * @return Retorna 1, caso seja possível obter o dado da cauda da lista que,
 * após a chamada da função estará armazenado em dado. Caso a lista seja inválida 
 * retorna -1. Caso seja vazia, retorna 0. Caso dado seja nulo retorna -1.
 */
int lista_info_cauda(lista_t *l, int *dado);

/**
 * @brief Obtém o dado armazenado em uma posição específica da lista
 * @details Obtém, se possível, o dado armazenado na posição pos da lista
 *
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cauda
 * @param pos A posição consultada. Posições válidas para consulta são:
 *            0 <= pos < tamanho
 *
 * @return Retorna 1, caso seja possível obter o dado da posição pos da lista
 * que após a chamada da função estará armazenado em dado. Caso a lista seja in-
 * válida retorna -1. Caso seja vazia, retorna 0. Caso a posição seja inválida,
 * retorna 0. Caso dado seja nulo retorna -1.
 */
int lista_info_posicao(lista_t *l, int *dado, int pos);

/**
 * @brief Insere um dado na cabeça da lista, isto é, na sua primeira posição.
 *
 * @details Insere o dado passado como parâmetro na primeira posição da lista.
 * A lista deve ser válida. Se não houver memória disponível a inserção não é
 * realizada.
 *
 * @param l A lista na qual o dado deve ser inserido.
 * @param dado O dado que deve ser inserido na lista.
 *
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso a
 * lista seja inválida, a função retorna -1. Caso não seja possível realizar a
 * inserção por falta de memória, a função deve retornar -1.
 */
int lista_insere_cabeca(lista_t *l, tipo dado);

/**
 * @brief Insere um dado na cauda da lista, isto é, na sua última posição.
 * @details Insere o dado passado como parâmetro na última posição da lista.
 * A lista deve ser válida. Se não houver memória disponível a inserção não é
 * realizada.
 *
 * @param l A lista na qual o dado deve ser inserido.
 * @param dado O dado que deve ser inserido na lista.
 *
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso a
 * lista seja inválida, a função retorna -1. Caso não seja possível realizar a
 * inserção por falta de memória, a função deve retornar -1.
 */
int lista_insere_cauda(lista_t *l, tipo dado);

/**
 * @brief Insere um dado em uma posição específica da lista.
 *
 * @details Insere um dado em uma posição específica da lista. Posições da lis-
 * ta são numeradas a partir de zero. Isto é, o primeiro elemente está na posi-
 * ção zero e o último na posição n-1, onde n é o número de elementos (tamanho).
 *
 * @param l A lista na qual o dado deve ser inserido. A lista deve estar pro-
 * priamente inicializada.
 * @param dado O dado que deve ser inserido na lista.
 * @param pos A posição na qual o dado deve ser inserido. Posições válidas para
 * inserção são: 0 <= pos <= tamanho
 *
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso a
 * lista seja inválida, a função retorna -1. Se a posição passada como parâme-
 * tro for inválida, a função retorna 0.
 */
int lista_insere_posicao(lista_t *l, tipo dado, int pos);

/**
 * @brief Remove o elemento da cabeça da lista (primeira posição)
 * @details Retorna o elemento da primeira posição da lista. O nó que contém o
 * elemento é removido da lista e desalocado. O dado contido na primeira posição
 * é armazenado no parâmetro dado, que é passado por referência para a função.
 *
 * @param l A lista na qual a remoção deve ser realizada.
 * @param dado Parâmetro passado por referência para armazenar o dado removido.
 *
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista seja
 * vazia, a função deve retornar 0. Se a lista não estiver inicializada, a fun-
 * ção retorna -1. Os valores retornados nos dois últimos casos servem para in-
 * dicar a quem chamou a função que o valor em dado não é corresponde a um va-
 * lor removido da lista, ou seja, ele continua inalterado. Caso dado seja nulo
 * retorna -1.
 */
int lista_remove_cabeca(lista_t *l, tipo *dado);

/**
 * @brief Remove o elemento da cauda da lista (última posição)
 * @details Retorna o elemento da última posição da lista. O nó que contém o
 * elemento é removido da lista e desalocado. O dado contido na última posição
 * é armazenado no parâmetro dado, que é passado por referência para a função.
 *
 * @param l A lista na qual a remoção deve ser realizada.
 * @param dado Parâmetro passado por referência para armazenar o dado removido.
 *
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista seja
 * vazia, a função deve retornar 0. Se a lista não estiver inicializada, a fun-
 * ção retorna -1. Os valores retornados nos dois últimos casos servem para in-
 * dicar a quem chamou a função que o valor em dado não é corresponde a um va-
 * lor removido da lista, ou seja, ele continua inalterado. Caso dado seja nulo
 * retorna -1.
 */
int lista_remove_cauda(lista_t *l, tipo *dado);

/**
 * @brief Remove o dado de uma determinada posição da lista
 * @details Remove o dado de uma determinada posição da lista (a posição deve
 * ser válida). O dado removido é armazenado no parâmetro dado, passado por re-
 * ferência. A remoção pode não ocorrer, caso a lista não seja válida ou esteja
 * vazia.
 *
 * @param l A lista da qual o dado deve ser removido
 * @param dado Parâmetro passado por referência. Caso a remoção ocorra, irá con-
 * ter o dado removido da posição solicitada.
 * @pos A posição que que deve ser removida da lista. Posições válidas são aque-
 * las que satisfazem: 0 <= pos < tamanho
 *
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista seja
 * vazia, a função deve retornar 0. Se a lista não estiver inicializada, a fun-
 * ção retorna -1. Se a posição passada como parâmetro for inválida, a função
 * retorna 0. Os valores retornados nos dois últimos casos servem para in-
 * dicar a quem chamou a função que o valor em dado não é corresponde a um va-
 * lor removido da lista, ou seja, ele continua inalterado. Caso dado seja nulo
 * retorna -1.
 */
int lista_remove_posicao(lista_t *l, tipo *dado, int pos);

/**
 * @brief Remove a primeira ocorrência de dado na lisa l
 * @details Remove somente a primeira ocorrência de dado na lista l.
 *
 * @param l A lista onde a remoção deve ocorrer.
 * @param dado O dado que deve ter a primeira ocorrência removida.
 *
 * @return Retorna a posição da qual o dado foi removido. Caso a lista seja in-
 * válida, a função retorna -1. Caso o dado não faça parte da lista, a função
 * retorna -2.
 */
int lista_remove_primeira(lista_t *l, tipo dado);

/**
 * @brief Remove todas as ocorrências do valor dado na lista l
 * @details Todas ocorrências de dado são removidas da lista, caso seja possível
 *
 * @param l A lista onde as remoções devem ocorrer.
 * @param dado O dado que deve ser removido da lista.
 *
 * @return Caso seja possível fazer as remoções, retorna o número de remoções
 * realizadas. Caso a lista seja inválida, retorna -1.
 */
int lista_remove_todas(lista_t *l, tipo dado);

/**
 * @brief Busca um dado na lista l
 * @details Busca por um dado em uma lista l, retornando sua posição.
 *
 * @param l A lista onde a busca deve ser feita.
 * @param dado O dado a ser buscado.
 *
 * @return Caso encontre, retorna sua posição na lista. Caso a lista seja invá-
 * lida, vazia ou não seja possível encontrar o elemento, a função retorna -1.
 */
int lista_busca_info(lista_t *l, tipo dado);

/**
 * @brief Determina a frequência de um dado na lista
 * @details Determina quantas vezes dado aparece na lista l.
 *
 * @param l A lista
 * @param dado O dado que deve ter a frequência determinada.
 *
 * @return A frequência com que dado aparece na lista. Retorna -1 caso a lista
 * seja inválida.
 */
int lista_frequencia_info(lista_t *l, tipo dado);

/**
 * @brief Verifica se uma lista está ordenada em ordem crescente de valores
 *
 * @details Verifica se uma lista está em ordem crescente de valores. A lista
 * deve ser válida. Uma lista vazia está ordenada.
 *
 * @param l A lista que deve ser verificada
 * @return Se a lista estiver em ordem, retorna 1. Caso esteja fora de ordem,
 * a função retorna 0. Para uma lista inválida, retorna -1.
 */
int lista_ordenada(lista_t *l);

/**
 * @brief Insere um elemento de forma ordenada em uma lista.
 *
 * @details Insere um elemento de forma ordenada na lista. A função assume que
 * a lista está ordenada. Isto é, a função não deve verificar internamente se a
 * lista está ou não ordenada. Este cuidado deve ser tomado por quem chama a
 * função.
 *
 * @param l A lista na qual a inserção deve ocorrer
 * @param dado O dado que deve ser inserido de forma ordenada
 *
 * @return Retorna 1 caso seja possível realizar a inserção e -1 caso contrário.
 */
int lista_insere_ordenado(lista_t *l, tipo dado);

/**
 * @brief Compara as listas l1 e l2 quanto à sua igualdade.
 * @details Compara se duas listas são iguais. Duas listas são iguais se e somen-
 * te se possuem o mesmo número de elementos e seus elementos são iguais, para
 * cada uma de suas posições.
 *
 * @param l1 A lista l1
 * @param l2 A lista l2
 *
 * @return Retorna: 1 caso as listas sejam iguais, 0 cao sejam diferentes. Duas
 * listas não inicializadas são iguais.
 */
int lista_compara(lista_t *l1, lista_t *l2);

/**
 * @brief Reverte a ordem dos elementos de uma lista
 * @details Reverte a ordem dos elementos de uma lista. Ao final, a lista estará
 * revertida. Exemplo: l antes <1, 4, 666, 7>; l depois <7, 666, 4, 1>.
 *
 * @param l A lista a ser revertida.
 * @return Retorna 1 caso seja possível fazer a reversão. Caso l seja inválida
 * retorna -1.
 */
int lista_reverte(lista_t *l);

/**
 * @brief Cria uma cópia da lista l
 * @details Cria uma nova lista que conterá uma cópia da lista l. A lista cópia
 * é retornada pela função. A lista original não deve ser alterada. Ou seja, l
 * continuará válida após a chamada da função. Note que embora os valores de l
 * e sua cópia sejam os mesmo após a chamada da função, seus nós são distintos,
 * isto é, cada lista possui seus próprios nós.
 *
 * @param l A lista a ser copiada.
 * @return Uma nova lista, que é uma cópia de l. Retorna NULL caso não seja
 * possível fazer a cópia.
 */
lista_t *lista_cria_copia(lista_t *l);

#endif
