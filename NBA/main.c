#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nba_stats.h"
#include "nba_stats.c"

int main()
{
	char nome[] = "jogadores.dat";
	int tamanho, i;
	jogador_t *jogadores = le_jogadores(nome, &tamanho);

	printf("Quantidade de jogadores: %i\n", tamanho);

	// for (i = 0; i < tamanho; i++)
	// {
	// 	printf("posicao %i: %s, %i, %s, %s, %i, %i, %i\n", i, jogadores[i].nome, jogadores[i].idade, jogadores[i].time, jogadores[i].posicao, jogadores[i].jogos, jogadores[i].minutos, jogadores[i].pontos);
	// }

	printf("Indice do jogador com mais arremessos: %i\n", statj_mais_arremessos(jogadores, tamanho, '2'));
	printf("Indice do jogador com mais cestas: %i\n", statj_mais_cestas(jogadores, tamanho, '3'));
	printf("Indice do jogador com melhor percentual: %i\n", statj_melhor_percentual(jogadores, tamanho, '2'));
	printf("Indice do jogador com mais jogos: %i\n", statj_jogos(jogadores, tamanho, '+'));
	printf("Indice do jogador com maior idade: %i\n", statj_idade(jogadores, tamanho, '+'));
	printf("Indice do jogador com mais minutos: %i\n", statj_minutos(jogadores, tamanho, '+'));
	printf("Indice do jogador com mais pontos: %i\n", statj_pontos(jogadores, tamanho, '+'));
	printf("Soma pontos do time: %i\n", statt_soma_pontos(jogadores, tamanho, "CLE"));
	printf("Media de pontos do time: %f\n", statt_media_pontos(jogadores, tamanho, "CLE"));
	printf("Media de idade do time: %f\n", statt_media_idade(jogadores, tamanho, "CLE"));
	printf("Jogadores em determinada posicao: %i\n", statt_posicao(jogadores, tamanho, "CLE", "PG"));

	return 0;
}
