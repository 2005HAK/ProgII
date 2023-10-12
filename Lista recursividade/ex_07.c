#include <stdio.h>
#include <stdlib.h>

int imprimelementos(int *vet){
    if (vet[(sizeof(vet) / sizeof(int)) - 1] != *vet){
        printf("%i ", *vet);
        imprimelementos(vet + 1);
    }
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5}; 
    imprimelementos(vet);
    return 0;
}