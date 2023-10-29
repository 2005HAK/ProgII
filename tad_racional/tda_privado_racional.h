#ifndef privado_racional_h
#define privado_racional_h

#include "tda_interface_racional.h"

/* estruturas privativas ao TDA */
struct racional {
	int num;
	int dem;
};

typedef struct racional racional_t;

/* operações privativas ao TDA */
int mdc(int a, int b);

#endif
