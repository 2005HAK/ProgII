#include <stdio.h>
#include <stdlib.h>

void calculaIntervalo(int num1, int num2){
    printf("%i ", num1);
    if(num1 != num2) calculaIntervalo(num1 + 1, num2);
}