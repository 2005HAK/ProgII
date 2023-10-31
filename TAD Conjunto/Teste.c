#include "conjunto_interface.h"
#include "conjunto_privado.h"
#include "conjunto.c"

int main(){
    //Criação co conjunto
    conjunto_t *a = conjunto_cria();
    conjunto_t *b = conjunto_cria();
    conjunto_t *c = conjunto_cria();
    conjunto_t *d = conjunto_cria();
    conjunto_t *e = conjunto_cria();


    //inserção de elementos
    for(elem_t i = 10; i < 50; i++) printf("%i deu certo A? %i\n", i, conjunto_insere_elemento(i, a));
    for(elem_t i = 15; i < 35; i++) printf("%i deu certo B? %i\n", i, conjunto_insere_elemento(i, b));
    conjunto_diferenca(a, b, c);
    conjunto_interseccao(a, b, d);
    

    //printa quantidade de elementos
    printf("Numero de elementos de A: %i \n", conjunto_numero_elementos(a));
    printf("Numero de elementos de B: %i \n", conjunto_numero_elementos(b));
    printf("Numero de elementos de C: %i \n", conjunto_numero_elementos(c));
    printf("Numero de elementos de D: %i \n", conjunto_numero_elementos(d));

    printf("Conjunto A: ");
    conjunto_imprime(a);

    //Remove elementos
    for(elem_t i = 20; i < 28; i++) conjunto_remove_elemento(i, a);
conjunto_uniao(a, b, e);
    //printa tamanho
    printf("Numero de elementos de A apos retirar 3 elemento: %i \n", conjunto_numero_elementos(a));

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

    conjunto_atribui(a, b);
    printf("Conjunto B: ");
    conjunto_imprime(b);

    conjunto_uniao(a, b, d);
    printf("Conjunto D: ");
    conjunto_imprime(d);

    printf("%i \n", conjunto_minimo(b));
    conjunto_destroi(&a);
    conjunto_destroi(&b);
    conjunto_destroi(&c);
    conjunto_destroi(&d);
    conjunto_destroi(&e);

    conjunto_imprime(b);
    return 0;
}