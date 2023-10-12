#include <stdio.h>
#include <stdlib.h>

calculaIntervalo(int num1, int num2){
    printf("%i ", num1);
    if(num1 != num2) calculaIntervalo(num1 + 1, num2);

}

int main(){
    calculaIntervalo(5, 10);
    return 0;
}