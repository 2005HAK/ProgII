#include <stdio.h>

int main(){
    int valor = 4;
    int *p = &valor;
    void *ptr = p;
    
    printf("%d", *(int*)ptr);

    return 0;
}