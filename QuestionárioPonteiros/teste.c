#include <stdio.h>

int main(){
    int zee = 9, zud = 1;
    int *tee = &zee, *tud = NULL;

    if(tee) zee++;
    if(!tud) zee--;

    printf("%d\n", zee);
    printf("%d", zud);
    return 0;
}