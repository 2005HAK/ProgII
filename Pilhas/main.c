#include "pilha.c"

int main(){
    int i, tam = 3;
    lista_t **containers = (lista_t**) malloc(sizeof(lista_t) * tam);
    
    for(i = 0; i < tam; i++){
        containers[i] = lista_cria();
        lista_insere_cauda(containers[i], i);
    }

    moveAAboveB(containers, 0, 1, tam);

    for(i = 0; i < tam; i++){
        printf("%i: ", i);
        lista_imprime(containers[i]);
    }
    return 0;
}