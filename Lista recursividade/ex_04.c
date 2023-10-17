#include <stdio.h>
#include <stdlib.h>

void somaIntervaloComIncremento(int num1,int num2, int num3){
    printf("%i ", num1);
    if(num1 + num3 <= num2) somaIntervaloComIncremento(num1 + num3, num2, num3);
}