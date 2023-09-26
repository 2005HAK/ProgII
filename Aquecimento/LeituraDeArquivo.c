#include <stdio.h>

int main(){
    FILE *arquivo = fopen("Programação/entrada.txt", "r+");

    fseek(arquivo,0, SEEK_END);

    return 0;
}