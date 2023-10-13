#include <stdio.h>
#include <stdlib.h>

void imprimeElementos(int *vet, int tam){
    printf("%i ", *vet);
    if(tam > 1) imprimeElementos(vet + 1, tam - 1);
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    imprimeElementos(vet, 10);
    return 0;
}