#include "conjunto_interface.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "conjunto_privado.h"
#include "conjunto.c"

int main(){
    //Criação co conjunto
    conjunto_t *conjunto = conjunto_cria();

    //inserção de elementos
    conjunto_insere_elemento(1, conjunto);
    conjunto_insere_elemento(2, conjunto);
    conjunto_insere_elemento(3, conjunto);
    conjunto_insere_elemento(4, conjunto);
    conjunto_insere_elemento(5, conjunto);
    conjunto_insere_elemento(6, conjunto);
    conjunto_insere_elemento(7, conjunto);
    conjunto_insere_elemento(8, conjunto);
    conjunto_insere_elemento(9, conjunto);
    conjunto_insere_elemento(10, conjunto);
    //Fim da inserção

    //Remove elementos
    conjunto_remove_elemento(4, conjunto);

    //Printa conjunto
    conjunto_imprime(conjunto);
    return 0;
}