#include "conjunto_interface.h"
#include "conjunto_privado.h"
#include "conjunto.c"

int main(){
    //Criação co conjunto
    conjunto_t *a = conjunto_cria();
    conjunto_t *b;
    conjunto_t *c = conjunto_cria();
    conjunto_t *d = conjunto_cria();
    conjunto_t *e = conjunto_cria();
    conjunto_inicializa_vazio(a);
    conjunto_inicializa_vazio(b);
    conjunto_inicializa_vazio(c);
    conjunto_inicializa_vazio(d);
    conjunto_inicializa_vazio(e);

    //inserção de elementos
    for(elem_t i = 1; i < 21; i++) conjunto_insere_elemento(i, a);
    for(elem_t i = 21; i < 31; i++) conjunto_insere_elemento(i, b);
    conjunto_diferenca(a, b, c);
    conjunto_interseccao(a, b, d);
    conjunto_uniao(a, b, e);

    //printa quantidade de elementos
    printf("Numero de elementos de A: %i \n", conjunto_numero_elementos(a));
    printf("Numero de elementos de B: %i \n", conjunto_numero_elementos(b));
    printf("Numero de elementos de C: %i \n", conjunto_numero_elementos(c));
    printf("Numero de elementos de D: %i \n", conjunto_numero_elementos(d));

    printf("Conjunto A: ");
    conjunto_imprime(a);

    //Remove elementos
    for(elem_t i = 2; i < 5; i++) conjunto_remove_elemento(i, b);

    //printa tamanho
    printf("Numero de elementos de A apos retirar um elemento: %i \n", conjunto_numero_elementos(a));

    //Printa conjunto
    printf("Conjunto A: ");
    conjunto_imprime(a);
    printf("Conjunto B: ");
    conjunto_imprime(b);
    printf("Conjunto C: ");
    conjunto_imprime(c);
    printf("Conjunto D: ");
    conjunto_imprime(d);
    printf("Conjunto E: ");
    conjunto_imprime(e);

    // conjunto_atribui(a, b);

    // conjunto_imprime(d);

    // conjunto_uniao(a, b, d);

    // conjunto_imprime(d);

    // printf("%i \n", conjunto_minimo(NULL));
    conjunto_destroi(&a);
    conjunto_destroi(&b);
    conjunto_destroi(&c);
    conjunto_destroi(&d);
    conjunto_destroi(&e);

    // conjunto_imprime(b);
    return 0;
}