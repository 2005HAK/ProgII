#include "abb.h"
#include "abb.c"
#include "abb_privado.h"
#include "abb_privado.c"

int main(){
    abb_t *arv = abb_cria();
    abb_insere(arv, 6);
    abb_remove(arv, 9);
    abb_insere(arv, 9);
    abb_insere(arv, 20);
    abb_insere(arv, 5);
    abb_insere(arv, 2);
    abb_remove(arv, 20);
    abb_remove(arv, 6);
    abb_insere(arv, 19);
    abb_insere(arv, 3);
    abb_insere(arv, 7);
    abb_insere(arv, 24);
    abb_insere(arv, 17);
    abb_insere(arv, 9);
    abb_insere(arv, 27);
    abb_remove(arv, 100);
    abb_insere(arv, 30);
    abb_insere(arv, 16);
    abb_remove(arv, 7);
    abb_insere(arv, 23);
    abb_insere(arv, 47);
    abb_insere(arv, 52);
    abb_destroi(&arv);
    return 0;
}