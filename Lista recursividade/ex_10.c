#include <stdio.h>
#include <stdlib.h>

int multiplicaNumeros(int num1, int num2){
    if(num2 == 1) return num1;
    return num1 + multiplicaNumeros(num1, num2 - 1);
}

int main()
{
    printf("%i ", multiplicaNumeros(200, 10000));
    return 0;
}