#include "lista.h"
#include "lista.c"

int main(){
    int dadoA = 0, dadoB = 0, dadoC = 0, i;

    lista_t *a = lista_cria();
    lista_t *b = lista_cria();
    lista_t *c = lista_cria();
    lista_t *d = lista_cria();

    for(i = 0; i < 11; i++) lista_insere_cabeca(a, i);
    lista_insere_cabeca(a, 5);
    lista_insere_cabeca(a, 5);
    lista_insere_cauda(a, 5);
    lista_insere_cauda(a, 5);
    for(i = 30; i < 61; i++) lista_insere_cabeca(b, i);
    for(i = 90; i < 111; i++) lista_insere_cabeca(c, i);
    for(i = 200; i < 250; i++) lista_insere_cauda(d, i);

    printf("=== Listas inicializadas? ===========================================================================\n\n");
    printf("A: %i\n", lista_inicializada(a));
    printf("B: %i\n", lista_inicializada(b));
    printf("C: %i\n", lista_inicializada(c));
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Tamanho das listas ==============================================================================\n\n");
    printf("De A: %i\n", lista_tamanho(a));
    printf("De B: %i\n", lista_tamanho(b));
    printf("De C: %i\n", lista_tamanho(c));
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Informacao na cabeca ============================================================================\n\n");
    
    lista_info_cabeca(a, &dadoA);
    lista_info_cabeca(b, &dadoB);
    lista_info_cabeca(c, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Informacao na cauda =============================================================================\n\n");
    lista_info_cauda(a, &dadoA);
    lista_info_cauda(b, &dadoB);
    lista_info_cauda(c, &dadoC);
    
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Imprime as listas ===============================================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_remove_cabeca(a, &dadoA);
    lista_remove_cabeca(b, &dadoB);
    lista_remove_cabeca(c, &dadoC);

    printf("=== Dado removido da cabeca =========================================================================\n\n");
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Imprime as listas apos remove cabeca ============================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_remove_cauda(a, &dadoA);
    lista_remove_cauda(b, &dadoB);
    lista_remove_cauda(c, &dadoC);

    printf("=== Dado removido da cauda ==========================================================================\n\n");
    printf("De A: %i\n", dadoA);
    printf("De B: %i\n", dadoB);
    printf("De C: %i\n", dadoC);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Imprime as listas apos remove cauda =============================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_remove_posicao(a, &dadoA, 8);
    lista_remove_posicao(b, &dadoB, 9);
    lista_remove_posicao(c, &dadoC, 15);

    printf("=== Dado removido ===================================================================================\n\n");
    printf("Da posicao 8 de A: %i\n", dadoA);
    printf("Da posicao 9 de B: %i\n", dadoB);
    printf("Da posicao 15 de C: %i\n", dadoC);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Imprime as listas apos remove as posicoes =======================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("-----------------------------------------------------------------------------------------------------\n");
    
    printf("=== Ocorrencias do numero ===========================================================================\n\n");
    printf("5 em A: %i\n", lista_frequencia_info(a, 5));
    printf("37 em B: %i\n", lista_frequencia_info(b, 37));
    printf("70 em C: %i\n", lista_frequencia_info(c, 70));
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Ordenado? =======================================================================================\n\n");
    printf("A: %i\n", lista_ordenada(a));
    printf("B: %i\n", lista_ordenada(b));
    printf("C: %i\n", lista_ordenada(c));
    printf("D: %i\n", lista_ordenada(d));
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_insere_ordenado(a, 12);
    lista_insere_ordenado(a, 9);
    lista_insere_ordenado(b, 29);
    lista_insere_ordenado(c, 49);
    lista_insere_ordenado(d, 109);

    printf("=== Imprime as listas apos inserir nas posicoes =======================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("D: ");
    lista_imprime(d);
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_reverte(a);
    lista_reverte(b);
    lista_reverte(c);
    lista_reverte(d);

    printf("=== Imprime as listas apos reverte-las ==============================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);
    printf("C: ");
    lista_imprime(c);
    printf("D: ");
    lista_imprime(d);
    printf("-----------------------------------------------------------------------------------------------------\n");

    lista_t *e = lista_cria_copia(a);

    printf("=== Imprime as listas apos criar a copia ============================================================\n\n");
    printf("A: ");
    lista_imprime(a);
    printf("E: ");
    lista_imprime(e);
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("=== Destruindo listas ===============================================================================\n\n...........\n...........\n...........\n");
    lista_destroi(&a);
    lista_destroi(&b);
    lista_destroi(&c);
    lista_destroi(&d);
    lista_destroi(&e);
    printf("-----------------------------------------------------------------------------------------------------\n");

    //retornos não testados ainda
}