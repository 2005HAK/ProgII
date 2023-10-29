#include "conjunto_interface.h"
#include "conjunto_privado.h"
#include "conjunto.c"

int main(){
    //Criação co conjunto
    conjunto_t *a = conjunto_cria();
    conjunto_t *b = conjunto_cria();
    conjunto_t *c = conjunto_cria();
    conjunto_t *d = conjunto_cria();
    conjunto_inicializa_vazio(a);
    // conjunto_inicializa_vazio(b);
    // conjunto_inicializa_vazio(c);
    // conjunto_inicializa_vazio(d);

    //inserção de elementos
    // for(elem_t i = 1; i < 21; i++) conjunto_insere_elemento(i, a);
    // for(elem_t i = 21; i < 31; i++) conjunto_insere_elemento(i, b);
    // conjunto_diferenca(a, b, c);
    // conjunto_interseccao(a, b, d);

    //printa capacidade
    // printf("Capacidade de elementos: %i \n", (a -> capacidade));
    // for(elem_t i = 9; i < 20; i++) conjunto_remove_elemento(i, a);
    // printf("Capacidade de elementos: %i \n", (a -> capacidade));
    // for(elem_t i = 0; i < 20; i++) conjunto_insere_elemento(i, b);

    //Remove elementos
    // conjunto_remove_elemento(8, a);

    // // //printa tamanho
    // // printf("Numero de elementos: %i \n", conjunto_numero_elementos(conjunto));

    // // //Printa conjunto
    // conjunto_imprime(a);
    //printf("%i", (a -> numero));

    conjunto_imprime(a);

    // conjunto_imprime(b);

    // conjunto_imprime(d);

    // conjunto_atribui(a, b);

    // conjunto_imprime(d);

    // conjunto_uniao(a, b, d);

    // conjunto_imprime(d);

    // printf("%i \n", conjunto_minimo(NULL));
    // conjunto_destroi(&b);

    // conjunto_imprime(b);
    return 0;
}