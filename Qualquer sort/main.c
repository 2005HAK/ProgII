#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam = 20, *v = (int*) malloc(sizeof(int) * tam);

    v[0] = 40;
    v[1] = 20;
    v[2] = 64;
    v[3] = 17;
    v[4] = 42;
    v[5] = 2;
    v[6] = 6;
    v[7] = 32;
    v[8] = 72;
    v[9] = 23;
    v[10] = 47;
    v[11] = 41;
    v[12] = 12;
    v[13] = 428;
    v[14] = 90;
    v[15] = 25;
    v[16] = 18;
    v[17] = 39;
    v[18] = 26;
    v[19] = 37;

    ordena(v, tam);

    for(int i = 0; i < tam; i++){
        printf("%i ", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}