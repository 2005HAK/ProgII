#include <stdio.h>
#include <stdlib.h>

unsigned long long int calcula(unsigned long long int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return calcula(n - 1) + calcula(n - 2);
}

int main(){
    int num;
    scanf("%i", &num);
    printf("%i", calcula(num));
}