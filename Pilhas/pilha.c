#include "pilha.h"

int ** criaContainers(int tam){
    int j = 0, valor = 0, i;
    int ** container = (int **) malloc (sizeof(int*) * tam);
    for(i = 0; i < tam; i++){
        container[i] = (int *) malloc(sizeof(int));
        container[i][j] = valor;
        valor++;
    }
    return container;
}

void moveAAboveB (int a, int b){
    
}

void moveAUpB (int a, int b){

}

void stackingAAboveB (int a, int b){

}

void stackingAUpB (int a, int b){

}

void exit (int ** container){

}

void printContainers (int ** containers, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%i: %i\n", i, containers[i][0]);
    }
}