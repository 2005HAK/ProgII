#include <stdio.h>
#include <stdlib.h>

int somaIntervalo(int num2){
    if(num2 > 0) return num2 + somaIntervalo(num2 - 1);   
    return 0;
}