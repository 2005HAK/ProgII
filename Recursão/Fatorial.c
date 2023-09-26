#include <stdio.h>
#include <stdlib.h>

int fat(unsigned int n){
    if (n <= 1) return 1;
    return n * fat(n - 1);
}

int main(){
    printf("%d\n", fat(6));
}