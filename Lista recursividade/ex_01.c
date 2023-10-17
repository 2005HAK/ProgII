#include <stdio.h>
#include <stdlib.h>

int calculaFatorial(int num){
    if(num <= 1) return 1;
    return num * calculaFatorial(num - 1);
}