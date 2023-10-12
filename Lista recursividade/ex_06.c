#include <stdio.h>
#include <stdlib.h>

int somaElementos(int *vet, int tam){
    if(tam == 0) return 0;
    else return vet[tam - 1] + somaElementos(vet, tam - 1);
}

int main(){
    int vet[] = {1, 2, 3, 4, 5, 10, 11, 14, 9, 7};
    printf("%i", somaElementos(vet, 10));
    return 0;
}