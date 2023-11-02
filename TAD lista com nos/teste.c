#include "lista.h"
#include "lista.c"

int main(){
    int dadoA = 0, dadoB = 0, dadoC = 0, i;

    lista_t *a = lista_cria();
    lista_t *b = lista_cria();
    lista_t *c = lista_cria();

    for(i = 0; i < 11; i++) lista_insere_cabeca(a, i);
    for(i = 30; i < 61; i++) lista_insere_cabeca(b, i);
    for(i = 90; i < 111; i++) lista_insere_cabeca(c, i);

    printf("=== Listas inicializadas? ========================================\n\n");
    printf("A: %i\n", lista_inicializada(a));
    printf("B: %i\n", lista_inicializada(b));
    printf("C: %i\n", lista_inicializada(c));
    printf("------------------------------------------------------------------\n");

    printf("=== Tamanho das listas ===========================================\n\n");
    printf("De A: %i\n", lista_tamanho(a));
    printf("De B: %i\n", lista_tamanho(b));
    printf("De C: %i\n", lista_tamanho(c));
    printf("------------------------------------------------------------------\n");

    printf("=== Informacao na cabeca =========================================\n\n");
    
    lista_info_cabeca(a, &dadoA);
    lista_info_cabeca(b, &dadoB);
    lista_info_cabeca(c, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("------------------------------------------------------------------\n");

    printf("=== Informacao na cauda ==========================================\n\n");
    lista_info_cauda(a, &dadoA);
    lista_info_cauda(b, &dadoB);
    lista_info_cauda(c, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("------------------------------------------------------------------\n");

    printf("=== Imprime as listas ============================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------\n");

    lista_remove_cabeca(a, &dadoA);
    lista_remove_cabeca(b, &dadoB);
    lista_remove_cabeca(c, &dadoC);

    printf("=== Imprime as listas apos remove cabeca ==========================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------\n");

    lista_remove_cauda(a, &dadoA);
    lista_remove_cauda(b, &dadoB);
    lista_remove_cauda(c, &dadoC);

    printf("=== Imprime as listas apos remove cauda ==========================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------\n");

    lista_destroi(&a);
    lista_destroi(&b);
    lista_destroi(&c);
}