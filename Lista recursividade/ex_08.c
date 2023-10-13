#include <stdio.h>
#include <stdlib.h>

void imprimeElementosInverso(int *vet, int tam){
    printf("%i ", vet[tam - 1]);
    if(tam > 1) imprimeElementosInverso(vet, tam - 1);
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    imprimeElementosInverso(vet, 10);
    return 0;
}