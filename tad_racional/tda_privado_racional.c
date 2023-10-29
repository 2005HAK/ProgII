#include "tda_privado_racional.h"

/* implementações das operações privadas */

int mdc(int a, int b)
{
	int aux, r;
	if(a < b) {
		aux = a;
		a = b;
		b = aux;
	}
	
	while(b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
