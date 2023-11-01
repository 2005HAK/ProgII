#include "lista.h"
#include "lista.c"

int main(){
    int dadoA = 0, dadoB = 0, dadoC = 0;

    lista_t *a = lista_cria();
    lista_t *b = lista_cria();
    lista_t *c = lista_cria();

    printf("=== Listas inicializadas? ========================================\n");
    printf("A: %i\n", lista_inicializada(a));
    printf("B: %i\n", lista_inicializada(b));
    printf("C: %i\n", lista_inicializada(c));
    printf("------------------------------------------------------------------\n");

    printf("=== Tamanho das listas ===========================================\n");
    printf("De A: %i\n", lista_tamanho(a));
    printf("De B: %i\n", lista_tamanho(b));
    printf("De C: %i\n", lista_tamanho(c));
    printf("------------------------------------------------------------------\n");

    printf("=== Informacao na cabeca =========================================\n");
    
    lista_info_cabeca(a, &dadoA);
    lista_info_cabeca(b, &dadoB);
    lista_info_cabeca(b, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("------------------------------------------------------------------\n");

    printf("=== Informacao na cauda ==========================================\n");
    lista_info_cauda(a, &dadoA);
    lista_info_cauda(b, &dadoB);
    lista_info_cauda(b, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("------------------------------------------------------------------\n");

    for(int i = 0; i < 11; i++){
        lista_insere_cabeca(a, i);
        lista_info_cabeca(a, &dadoA);
        printf("%i ", dadoA);
    } 

    lista_destroi(&a);
    lista_destroi(&b);
    lista_destroi(&c);
}