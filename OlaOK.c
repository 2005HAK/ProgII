#include <stdio.h>
#include <string.h>

int main() {
  char palavra[20];
  int i = 1;

  while(i != 0){
    scanf("%s", palavra);

    if(strcmp(palavra, "HELLO") == 0){
        printf("Caso %i: INGLES\n", i);
        i++;
    }else if(strcmp(palavra, "HOLA") == 0){
        printf("Caso %i: ESPANHOL\n", i);
        i++;
    }else if(strcmp(palavra, "HALLO") == 0){
        printf("Caso %i: ALEMAO\n", i);
        i++;
    }else if(strcmp(palavra, "BONJOUR") == 0){
        printf("Caso %i: FRANCES\n", i);
        i++;
    }else if(strcmp(palavra, "CIAO") == 0){
        printf("Caso %i: ITALIANO\n", i);
        i++;
    }else if(strcmp(palavra, "ZDRAVSTVUJTE") == 0){
        printf("Caso %i: RUSSO\n", i);
        i++;
    }else if(strcmp(palavra, "#") == 0){
        i = 0;
    }else{
        printf("Caso %i: DESCONHECIDO\n", i);
        i++;
    }
  }
  return 0;
}