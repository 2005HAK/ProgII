#ifndef _pilha_
#define _pilha_

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria os conteiners
 *
 * @details Cria uma matriz alocada dinamicamente com os containers inicializados em suas devidas posições
 * 
 * @param tam Quantidade de containers
 *
 * @return Retorna a matriz de containers
 */
int ** criaContainers(int tam);

/**
 * @brief Move a sobre b
 * 
 * @details Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
 * exatamente sobre o container identificado por b. Antes, porém, quaisquer containers que
 * estiverem sobre a e b são retornados às suas posições originais no pátio da empresa.
 * 
 * @param a Número do container que sera colocado acima de outro
 * @param b Número do container que terá o a em cima
 * 
 * @return Vazio
*/
void moveAAboveB (int a, int b);

/**
 * @brief Move a topo b
 * 
 * @details Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
 * no topo da pilha de containers que contém o container identificado por b. Antes, porém,
 * quaisquer containers que estiverem sobre a são retornados a sua posição inicial.
 * 
 * @param a Número do container que sera colocado na pilha de outro
 * @param b Número do container que terá o a em cima
 * 
 * @return Vazio
*/
void moveAUpB (int a, int b);

/**
 * @brief Empilha a sobre b
 * 
 * @details Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
 * estiverem acima de a (ou seja, a pilha de containers definida a partir de a) para a posição
 * exatamente acima do container b. Antes, porém, quaisquer containers que estiverem sobre b
 * devem ser retornados às suas posições originais no pátio da empresa. Os containers que
 * estiverem acima de a devem manter a ordem inicial em que estavam.
 * 
 * @param a Número do container que sera colocado na pilha de outro
 * @param b Número do container que terá o a tem cima
 * 
 * @return Vazio
*/

void stackingAAboveB (int a, int b);
/**
 * @brief Empilha a sobre b
 * 
 * @details Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
 * estiverem acima de a (ou seja, a pilha de containers definida a partir de a) acima do topo da pilha
 * que contém o container b. Os containers que estiverem acima de a devem manter a ordem inicial
 * em que estavam, assim como os containers abaixo e acima de b.
 * 
 * @param a Número do container que sera colocado na pilha de outro
 * @param b Número do container que terá o a tem cima
 * 
 * @return Vazio
*/
void stackingAUpB (int a, int b);

/**
 * @brief Termina as movimentações
 * 
 * @details Encerra a execução do programa e mostra o estado das pilhas de containers. 
 * 
 * @param container Container a ser parado
 * 
 * @return Vazio
*/
void exit (int ** container);

/**
 * @brief Exibe os containers
 *
 * @details Imprime a posição dos containers e quais containers estão em cada posição
 *
 * @param containers Matriz de containers
 * @param tam Qauntidade de containers inicial/quantidade de posições
 *
 * @return Vazio
 */
void printContainers (int ** containers, int tam);

#endif