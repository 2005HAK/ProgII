#include <stdio.h>
#include <stdlib.h>

int realizaPotencia(int num1, int num2){
    if(num2 == 0) return 1;
    if(num2 == 1) return num1;
    return num1 * realizaPotencia(num1, num2 - 1);
}

int main(){
    printf("%i", realizaPotencia(2, 10));
    return 0;
}