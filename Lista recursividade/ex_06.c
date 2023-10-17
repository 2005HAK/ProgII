#include <stdio.h>
#include <stdlib.h>

int somaElementos(int *vet, int tam){
    if(tam == 0) return 0;
    return vet[tam - 1] + somaElementos(vet, tam - 1);
}