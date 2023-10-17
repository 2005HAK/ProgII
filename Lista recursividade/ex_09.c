#include <stdio.h>
#include <stdlib.h>

void inverteVetor(int *vet, int tam){
    if (tam - 1 > 0){
        int valorTemp = vet[0];
        vet[0] = vet[tam - 1];
        vet[tam - 1] = valorTemp;
        inverteVetor(vet + 1, tam - 2);
    }
}