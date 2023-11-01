#include "lista.h"
#include "lista.c"

int main(){
    int valorInsere = 12, valorBusca = 8, valorA, valorB, valorC;

    //Cria listas
    lista_t *a = lista_cria(10);
    lista_t *b = lista_cria(10);
    lista_t *c = lista_cria(10);

    //Insere cabeça
    for(int i = 0; i < 11; i++) lista_insere_cabeca(a, i);
    for(int i = 1; i < 11; i++) lista_insere_cabeca(b, i);
    for(int i = 15; i < 21; i++) lista_insere_cabeca(c, i);

    //Verifica tamanho
    printf("=========== Tamanho ==========================================================\n");
    printf("De A: %i\n", lista_tamanho(a));
    printf("De B: %i\n", lista_tamanho(b));
    printf("De C: %i\n", lista_tamanho(c));
    printf("------------------------------------------------------------------------------\n");

    //Verifica capacidade
    printf("=========== Capacidade =======================================================\n");
    printf("De A: %i\n", lista_capacidade(a));
    printf("De B: %i\n", lista_capacidade(b));
    printf("De C: %i\n", lista_capacidade(c));
    printf("------------------------------------------------------------------------------\n");

    //Verifica se está cheia
    printf("=========== Lista cheia (1 - Sim, 0 - Nao) ===================================\n");
    printf("Lista A? %i\n", lista_cheia(a));
    printf("Lista B? %i\n", lista_cheia(b));
    printf("Lista C? %i\n", lista_cheia(c));
    printf("------------------------------------------------------------------------------\n");

    //Valores na cabeça
    lista_info_cabeca(a, &valorA);
    lista_info_cabeca(b, &valorB);
    lista_info_cabeca(c, &valorC);

    printf("=========== Valor na cabeca ==================================================\n");
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Valores na cauda
    lista_info_cauda(a, &valorA);
    lista_info_cauda(b, &valorB);
    lista_info_cauda(c, &valorC);

    printf("=========== Valor na cauda ===================================================\n");
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Valores na posição
    lista_info_posicao(a, &valorA, valorBusca);
    lista_info_posicao(b, &valorB, valorBusca);
    lista_info_posicao(c, &valorC, valorBusca);

    printf("=========== Valor na posicao %i ==============================================\n", valorBusca);
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");
    
    //Imprime as listas
    printf("=========== Valores das listas antes de inserir na cauda =====================\n");
    printf("Lista A: ");
    lista_imprime(a);
    printf("Lista B: ");
    lista_imprime(b);
    printf("Lista C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------------------\n");

    //Insere cauda
    for(int i = 11; i < 31; i++) lista_insere_cauda(a, i);
    for(int i = 11; i < 26; i++) lista_insere_cauda(b, i);
    for(int i = 21; i < 29; i++) lista_insere_cauda(c, i);

    //Imprime as listas
    printf("=========== Valores das listas depois de inserir na cauda ====================\n");
    printf("Lista A: ");
    lista_imprime(a);
    printf("Lista B: ");
    lista_imprime(b);
    printf("Lista C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------------------\n");

    //Inverte listas
    lista_reverte(a);
    lista_reverte(b);
    lista_reverte(c);

    //Imprime as listas
    printf("=========== Valores das listas depois de inverter valores ====================\n");
    printf("Lista A: ");
    lista_imprime(a);
    printf("Lista B: ");
    lista_imprime(b);
    printf("Lista C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------------------\n");

    //Insere na posição
    lista_insere_posicao(a, valorInsere, valorBusca);
    lista_insere_posicao(b, valorInsere, valorBusca);
    lista_insere_posicao(c, valorInsere, valorBusca);
    
    //Imprime as listas
    printf("=========== Valores das listas depois de inserir na posicao %i o valor %i ====\n", valorBusca, valorInsere);
    printf("Lista A: ");
    lista_imprime(a);
    printf("Lista B: ");
    lista_imprime(b);
    printf("Lista C: ");
    lista_imprime(c);
    printf("------------------------------------------------------------------------------\n");

    //Remove cauda
    lista_remove_cauda(a, &valorA);
    lista_remove_cauda(b, &valorB);
    lista_remove_cauda(c, &valorC);

    //Imprime as listas
    printf("=========== Valor removido da cauda ==========================================\n");
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Remove cabeca
    lista_remove_cabeca(a, &valorA);
    lista_remove_cabeca(b, &valorB);
    lista_remove_cabeca(c, &valorC);

    //Imprime as listas
    printf("=========== Valor removido da cabeca =========================================\n");
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Remove na posicao
    lista_remove_posicao(a, &valorA, valorBusca);
    lista_remove_posicao(b, &valorB, valorBusca);
    lista_remove_posicao(c, &valorC, valorBusca);

    //Imprime as listas
    printf("=========== Valor removido da posicao %i =====================================\n", valorBusca);
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Remove primeira ocorrencia
    lista_remove_primeira(a, valorInsere);
    lista_remove_primeira(b, valorInsere);
    lista_remove_primeira(c, valorInsere);

    //Imprime as listas
    printf("=========== Remove a primeira ocorrencia do valor %i =========================\n", valorInsere);
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Remove todas as ocorrencias
    lista_remove_todas(a, valorInsere);
    lista_remove_todas(b, valorInsere);
    lista_remove_todas(c, valorInsere);

    //Imprime as listas
    printf("=========== Remove todas as ocorrencias do valor %i ==========================\n", valorInsere);
    printf("De A: %i\n", valorA);
    printf("De B: %i\n", valorB);
    printf("De C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Busca um valor
    valorA = lista_busca_info(a, valorBusca);
    valorB = lista_busca_info(b, valorBusca);
    valorC = lista_busca_info(c, valorBusca);

    //Imprime as listas
    printf("=========== Verifica a posicao em que %i aparece =============================\n", valorBusca);
    printf("Posicao em A: %i\n", valorA);
    printf("Posicao em B: %i\n", valorB);
    printf("Posicao em C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Busca um valor
    valorA = lista_frequencia_info(a, valorBusca);
    valorB = lista_frequencia_info(b, valorBusca);
    valorC = lista_frequencia_info(c, valorBusca);

    //Imprime as listas
    printf("=========== Frequencia que %i aparece ========================================\n", valorBusca);
    printf("Em A: %i\n", valorA);
    printf("Em B: %i\n", valorB);
    printf("Em C: %i\n", valorC);
    printf("------------------------------------------------------------------------------\n");

    //Imprime as listas
    printf("=========== A lista e ordenada? ========================================\n");
    printf("A: %i\n", lista_ordenada(a));
    printf("B: %i\n", lista_ordenada(b));
    printf("C: %i\n", lista_ordenada(c));
    printf("------------------------------------------------------------------------------\n");

    //Imprime as listas
    printf("=========== As listas sao iguais? ========================================\n");
    printf("A e B: %i\n", lista_compara(a, b));
    printf("B e C: %i\n", lista_compara(b, c));
    printf("C e A: %i\n", lista_compara(c, a));
    printf("------------------------------------------------------------------------------\n");

    //Destroi as listas
    lista_destroi(&a); 
    lista_destroi(&b); 
    lista_destroi(&c); 
}