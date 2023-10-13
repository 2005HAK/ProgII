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

int main()
{
    int vet[] = {1, 2, 3, 4}; 
    inverteVetor(vet, 4);
    for(int i = 0; i < 4; i++){
        printf("%i ", vet[i]);
    }
    return 0;
}