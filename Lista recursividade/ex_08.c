#include <stdio.h>
#include <stdlib.h>

void imprimeElementosInverso(int *vet, int tam){
    printf("%i ", vet[tam - 1]);
    if(tam > 1) imprimeElementosInverso(vet, tam - 1);
}