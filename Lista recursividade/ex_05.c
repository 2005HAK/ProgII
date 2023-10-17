#include <stdio.h>
#include <stdlib.h>

int realizaPotencia(int base, int expoente){
    if(expoente == 0) return 1;
    if(expoente == 1) return base;
    return base * realizaPotencia(base, expoente - 1);
}