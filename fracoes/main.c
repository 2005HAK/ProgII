#include <stdio.h>
#include "fracao.h"

int main() {
	fracao_t *f;
	f = cria_fracao(2,3);
	//f->num = 2;       //retire o comentario e veja o que acontece. nao funciona
	imprime_fracao(f);
	//imprime_numerador(f); //retire este comentario dps. nao funciona
	destroi_fracao(&f);
	return 0;
}