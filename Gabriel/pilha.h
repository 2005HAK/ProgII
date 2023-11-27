#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no no_t;
typedef struct lista lista_t;

int busca (lista_t **vetor, int a);

// Cria uma sequencia de containers e aloca cada container em sua posicao
lista_t **aloca_container(int qtd);

lista_t* lista_cria	();

int	lista_insere_cauda	(lista_t *l, int dado);
int	lista_remove_cauda	(lista_t *l);

/*
mova a sobre b
Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
exatamente sobre o container identificado por b. Antes, porém, quaisquer containers que
estiverem sobre a e b são retornados às suas posições originais no pátio da empresa.
*/
void move_a_sobre_b (lista_t** vetor, int a, int b);

/*
• mova a topo b
Onde a e b são números de containers. Esta movimentação coloca o container identificado por a
no topo da pilha de containers que contém o container identificado por b. Antes, porém,
quaisquer containers que estiverem sobre a são retornados a sua posição inicial.
*/
void move_a_topo_b (lista_t **vetor, int a, int b);

/*
• empilhe a sobre b
Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
estiverem acima de a (ou seja, a pilha de containers definida a partir de a) para a posição
exatamente acima do container b. Antes, porém, quaisquer containers que estiverem sobre b
devem ser retornados às suas posições originais no pátio da empresa. Os containers que
estiverem acima de a devem manter a ordem inicial em que estavam.
*/
void empilha_a_sobre_b (lista_t **vetor, int a, int b);

/*
• empilhe a topo b
Onde a e b são números de containers. Movimenta o container a e quaisquer containers que
estiverem acima de a (ou seja, a pilha de containers definida a partir de a) acima do topo da pilha
que contém o container b. Os containers que estiverem acima de a devem manter a ordem inicial
em que estavam, assim como os containers abaixo e acima de b.
*/
void empilha_a_topo_b (lista_t **vetor, int a, int b);

/*
• sair
Encerra a execução do programa e mostra o estado das pilhas de containers. 
*/
void sair (lista_t **vetor, int tamanho);