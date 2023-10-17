#include <stdio.h>
#include <stdlib.h>

void imprimeElementos(int *vet, int tam){
    printf("%i ", *vet);
    if(tam > 1) imprimeElementos(vet + 1, tam - 1);
}