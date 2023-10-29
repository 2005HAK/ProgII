#include "tda_privado_racional.h"
#include <stdio.h>
#include <stdlib.h>

/* implementação das operações do TDA */
racional_t *cria_racional(int numerador, int denominador)
{
	racional_t * p = NULL;
	p = (racional_t *) malloc(sizeof(racional_t));
	if(denominador != 0 && p != NULL) {
		p->num = numerador;
		p->dem = denominador;
	}
	return p;
}
void destroi_racional(racional_t ** pp)
{
	if(pp != NULL) {
		free(*pp);
		*pp = NULL;
	}
}

void reduz_racional(racional_t *p)
{
	int m;
	m = mdc(p->num, p->dem);
	p->num = p->num / m;
	p->dem = p->dem / m;
}

racional_t *soma_racional(racional_t * a, racional_t * b)
{
	racional_t *p;
	p = (racional_t *) malloc(sizeof(racional_t));
	if(p != NULL) {
		p->num = a->num * b->dem + b->num * a->dem;
		p->dem = a->dem * b->dem;
	}
	reduz_racional(p);
	return p;
}

void mostra_racional(racional_t *p)
{
	reduz_racional(p);
	printf("%d/%d", p->num, p->dem);
}

