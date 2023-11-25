
#ifndef _lista_de_
#define _lista_de_

#include <stdio.h>
#include <stdlib.h>

typedef struct no no_t;
typedef struct lista lista_t;
typedef int tipo;

/**
 * @brief Cria containers
 * 
 * @details Cria varias posições de containers devidamente inicializadas
 * 
 * @param tam Quantidade de containers que serão criados
*/
lista_t **criaContainers(int tam);

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
 * @brief Imprime a lista l
 * @details Imprime os elementos de lista l com espaço entre cada elemento
 * 
 * @param l Lista a ser impressa
 * @return Não possui retorno
*/
void lista_imprime(lista_t *l);

/**
 * @brief Move a sobre b
 * 
 * @details Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
 * exatamente sobre o container identificado por b. Antes, porém, quaisquer containers que
 * estiverem sobre a e b são retornados às suas posições originais no pátio da empresa.
 * 
 * @param c Matriz de containers
 * @param a Valor a ser movido
 * @param b Valor que tera a sobre ele
 * @param tam Quantidade de containers
*/
void moveAAboveB (lista_t **c, int a, int b, int tam);

/**
 * @brief Move a topo b
 * 
 * @details Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
 * no topo da pilha de containers que contém o container identificado por b. Antes, porém,
 * quaisquer containers que estiverem sobre a são retornados a sua posição inicial.
 * 
 * @param c Matriz de containers
 * @param a Valor a ser movido
 * @param b Valor que tera a no topo de sua pilha
 * @param tam Quantidade de containers
*/
void moveAUpB (lista_t **c, int a, int b, int tam);

/**
 * @brief Empilha a sobre b
 * 
 * @details Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
 * estiverem acima de a (ou seja, a pilha de containers definida a partir de a) para a posição
 * exatamente acima do container b. Antes, porém, quaisquer containers que estiverem sobre b
 * devem ser retornados às suas posições originais no pátio da empresa. Os containers que
 * estiverem acima de a devem manter a ordem inicial em que estavam.
 * 
 * @param c Matriz de containers
 * @param a Valor inicial da sub pilha que sera movida
 * @param b Valor que tera a sub pilha sobre ele
 * @param tam Quantidade de containers
*/
void stackingAAboveB (lista_t **c, int a, int b, int tam);

/**
 * @brief Empilha a topo b
 * 
 * @details Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
 * estiverem acima de a (ou seja, a pilha de containers definida a partir de a) acima do topo da pilha
 * que contém o container b. Os containers que estiverem acima de a devem manter a ordem inicial
 * em que estavam, assim como os containers abaixo e acima de b.
 * 
 * @param c Matriz de containers
 * @param a Valor inicial da sub pilha que sera movida
 * @param b Valor que tera a sub pilha sobre sua pilha
 * @param tam Quantidade de containers
*/
void stackingAUpB (lista_t **c, int a, int b, int tam);

/**
 * @brief Sair
 * 
 * @details Encerra a execução do programa e mostra o estado das pilhas de containers.
 * 
 * @param c Matriz de containers
 * @param tam Quantidade de containers
*/
void exitContainers (lista_t **c, int tam);

#endif
