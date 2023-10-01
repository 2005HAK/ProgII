#include <stdio.h>

int main(){
    int *p = NULL, *q = 0;

    if(p)printf("P");
    else printf("X");
    if(q)printf("Q");
    else printf("Y");

    return 0;
}