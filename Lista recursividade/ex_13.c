#include <stdio.h>
#include <stdlib.h>

int calculaFibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return calculaFibonacci(n - 1) + calculaFibonacci(n - 2);
}