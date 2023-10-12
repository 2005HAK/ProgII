#include <stdio.h>
#include <stdlib.h>

int somaIntervalo(int num2){
    if(num2 > 0) printf("%i ", somaIntervalo(num2 - 1));
    return num2 + 1;
}

int main(){
    somaIntervalo(30);
    return 0;
}