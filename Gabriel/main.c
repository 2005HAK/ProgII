#include "pilha.h"

// aloca containers : PARECE FUNCIONAR
//move a sobre b : NECESSITA TESTES
// move a topo b : NECESSITA TESTES
// empilha a sobre b : NECESSITA TESTES
// empilha a topo a : NECESSITA TESTES
//sai : NECESSITA TESTES

int main(){
    int i, j = 0, aa, bb;
    char funcao[20], explica[20], a[20], b[20];
    lista_t **lista;

    scanf("%d", &i);
    lista = aloca_container(i);
    int x = 9, y = 1;
    move_a_sobre_b(lista, x, y);
    x = 8, y = 1;
    move_a_topo_b(lista, x, y);
    x = 7, y = 1;
    move_a_topo_b(lista, x, y);
    x = 6, y = 1;
    move_a_topo_b(lista, x, y);
    x = 8; y = 6;
    empilha_a_topo_b(lista, x, y);
    x = 8; y = 5;
    empilha_a_topo_b(lista, x, y);
    x = 2, y = 1;
    move_a_topo_b(lista, x, y);
    x = 8, y = 0;
    move_a_topo_b(lista, x, y);

    sair(lista, i);

    /*if(i > 0 && i < 2500){
        lista = aloca_container(i);
         do{
            scanf("%s", funcao);

            if(strcmp(funcao, "sair") != 0){
                scanf("%s %s %s", a, explica, b);
                aa = atoi(a);
                bb = atoi(b);

                if(strcmp (funcao, "mova") == 0){
                    if(strcmp(explica, "sobre") == 0){
                        move_a_sobre_b(lista, aa, bb);
                    }
                    else{
                        move_a_topo_b(lista, aa, bb);
                    }
                }
                else{
                    if(strcmp(explica, "sobre") == 0){
                        empilha_a_sobre_b(lista, aa, bb);
                    }
                    else{
                        empilha_a_topo_b(lista, aa, bb);
                    }
                }
            }
            else{
                sair(lista, i);
                j = 1;
            }
         } while(j == 0);
    }*/
    return 0;
}