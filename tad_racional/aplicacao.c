#include "aplicacao.h"
#include <stdio.h>

int main(void)
{
	racional_t *a, *b, *c;
	a = cria_racional(3, 5);
	b = cria_racional(6, 3);
	c = soma_racional(a, b);
	mostra_racional(a);
	printf(" + ");
	mostra_racional(b);
	printf(" = ");
	mostra_racional(c);
	printf("\n");
	destroi_racional(&a);
	printf("Endereco de a = %p\n", a);
	destroi_racional(&b);
	destroi_racional(&c);
}
