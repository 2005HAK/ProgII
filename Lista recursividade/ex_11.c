#include <stdio.h>
#include <stdlib.h>

int calculaMDC(int num1, int num2){
    if(num2 == 0) return num1;
    return calculaMDC(num2, num1%num2);
}