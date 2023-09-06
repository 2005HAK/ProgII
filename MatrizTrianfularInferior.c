#include <stdio.h>

int main(){
    int tam;

    scanf("%i", &tam);

    int **matriz = (int**) malloc(4 * sizeof(int*));

    for(int i = 0; i < tam; i++){
        matriz[i] = (int*) malloc((i + 1) * sizeof(int));
        matriz[i][i] = 1;
    }

    for(int i = 0; i < tam; i++){
        for(int j = 1; j < tam; j++){
            matriz[i][j] = 1;
        }
        
    }
}