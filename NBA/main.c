#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nba_stats.h"
#include "nba_stats.c"

int main()
{
	char nome[] = "jogadores.dat";
	int tamanho = le_cabecario(nome), i;
	jogador_t *jogadores = le_jogadores(nome, &tamanho);

	printf("Quantidade de jogadores: %i\n", tamanho);

	for (i = 0; i < tamanho; i++)
	{
		printf("posicao %i: %i\n", i, jogadores[i].idade);
	}

	return 0;
}
