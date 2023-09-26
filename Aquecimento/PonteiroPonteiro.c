#include <stdio.h>

void troca(int **i, int **j){
    int *k = *j;
    *j = *i;
    *i = k;
}

int main(){
    int x = 3, y = 5;
    int mat[3][4];
    int *i = &x, *j = &y;

    printf("%i %i\n", *i, *j);

    troca(&i, &j);

    printf("%i %i\n", *i, *j);
}