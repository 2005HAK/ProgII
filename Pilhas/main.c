#include "pilha.c"
#include "string.h"

int main(){
    int i, tam = 0;
    char comando[30];
    char funcao[10];
    char a[5];
    char subfuncao[10];
    char b[5];
    int numa;
    int numb;

    scanf("%i", &tam);

    if(tam > 0 && tam < 2500){
        lista_t **containers = criaContainers(tam);

        do{
            scanf("%s", funcao);
            if(strcmp(funcao, "sair") != 0){
                scanf("%s %s %s", a, subfuncao, b);
                numa = atoi(a);
                numb = atoi(b);

                if(strcmp(funcao, "mova") == 0){
                    if(strcmp(subfuncao, "sobre") == 0){
                        moveAAboveB(containers, numa, numb, tam);
                    }else{
                        moveAUpB(containers, numa, numb, tam);
                    }
                }else {
                    if(strcmp(subfuncao, "sobre") == 0){
                        stackingAAboveB(containers, numa, numb, tam);
                    }else{
                        stackingAUpB(containers, numa, numb, tam);
                    }
                }
            }
            
        }while(strcmp(funcao, "sair") != 0);

        exitContainers(containers, tam);
    }
    
    return 0;
}