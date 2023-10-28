#include "conjunto_interface.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "conjunto_privado.h"
#include "conjunto.c"

int main(){
    //Criação co conjunto
    conjunto_t *a = conjunto_cria();
    conjunto_t *b = conjunto_cria();
    conjunto_t *c = conjunto_cria();
    conjunto_t *d = conjunto_cria();

    //inserção de elementos
    for(elem_t i = 1; i < 20; i++) conjunto_insere_elemento(i, a);
    for(elem_t i = 19; i < 19; i++) conjunto_insere_elemento(i, b);
    // conjunto_diferenca(a, b, c);
    // conjunto_interseccao(a, b, d);

    // // //printa tamanho
    // // printf("Numero de elementos: %i \n", conjunto_numero_elementos(conjuntoA));

    // // //Remove elementos
    // // for(elem_t i = 10; i < 21; i++) conjunto_remove_elemento(i, conjunto);

    // // //printa tamanho
    // // printf("Numero de elementos: %i \n", conjunto_numero_elementos(conjunto));

    // // //Printa conjunto
    // conjunto_imprime(a);

    conjunto_imprime(b);

    // conjunto_imprime(c);

    // conjunto_imprime(d);

    // conjunto_atribui(a, d);

    // conjunto_imprime(d);

    // conjunto_uniao(a, b, d);

    // conjunto_imprime(d);

    printf("%i \n", conjunto_minimo(NULL));
    conjunto_destroi(&b);

    conjunto_imprime(b);
    return 0;
}