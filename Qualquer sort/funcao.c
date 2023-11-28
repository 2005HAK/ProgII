#include "funcao.h"
#include <ctype.h>
#include <stdlib.h>

int ordena(int *vetor, unsigned int t){
    if(vetor != NULL && t != 0){
        mergeSort(vetor, t);
        return 1;
    } return 0;
}

void mergeSort(int *vetor, int tam){
    if(tam > 1){
        int med = tam / 2;
        mergeSort(vetor, med);
        mergeSort(vetor + med, tam - med);
        merge(vetor, tam);
    }
}

void merge(int *vetor, int tam){
    int med, i = 0, j, k = 0, *tmp;
    tmp = (int*) malloc(tam * sizeof(int));

    med = tam / 2;
    j = med;
    while(i < med && j < tam){
        if(vetor[i] <= vetor[j]) tmp[k] = vetor[i++];
        else tmp[k] = vetor[j++];
        k++;
    }
    if(i == med) while(j < tam) tmp[k++] = vetor[j++];
    else while (i < med) tmp[k++] = vetor[i++];
    for(i = 0; i < tam; i++) vetor[i] = tmp[i];

    free(tmp);
}