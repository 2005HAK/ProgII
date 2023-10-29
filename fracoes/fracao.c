#include "fracao.h"

struct fracao {
	int num;
	int den;
};

//Essa funcao é "privada". so pode ser chamada neste arquivo
static void imprime_numerador(fracao_t *f) {
	printf("debug:::numerador: %d",f->num);
}

void imprime_fracao(fracao_t *f) {
	printf("%d/%d\n",f->num,f->den);
}

fracao_t* cria_fracao(int n, int d) {
	if (d == 0) return NULL;
	fracao_t *f = (fracao_t*) malloc(sizeof(fracao_t));
	f->num = n;
	f->den = d;
	return f;
}

void destroi_fracao(fracao_t **f) {
	//imprime_numerador(*f); //descomente para testar... isso funciona... funcao "privada"
	if(f != NULL) {
		free(*f);
		*f = NULL;
	}
}