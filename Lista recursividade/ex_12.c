#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Retorna 1 se é palindromo e retorna 0 se não é 
*/
int verificaPalindromo(char *palavra){
    int tam = strlen(palavra);
    if(tam == 0 || tam == 1) return 1;
    if(palavra[0] == palavra[tam - 1] || (palavra[0] + 32) == palavra[tam - 1] || palavra[0] == (palavra[tam - 1] + 32)){
        palavra[tam - 1] = '\0';
        return verificaPalindromo(palavra + 1);
    }
    return 0;
}

int main()
{
    char palavra[] = "Sos";
    printf("%i", verificaPalindromo(palavra));
    return 0;
}