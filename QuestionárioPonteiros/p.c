#include <stdio.h>

int main(){
    int i = 10;
    float f = 6.66;

    int *pi = &i;
    int *pf = &f;

    void **p;
    
    p = (void**) &pi;
    printf("%d,", **(int**)p);
    p = (void**) &pf;
    printf("%.2f.", **(float**)p);

    return 0;
}