#include "nba_stats.h"

int le_cabecario(char *nome)
{
    if (nome != NULL)
    {
        FILE *arquivo = fopen(nome, "r");
        if (arquivo != NULL)
        {
            int tamanho;
            fread(&tamanho, sizeof(int), 1, arquivo);
            fclose(arquivo);
            return tamanho;
        }
        return 0;
    }
    return -1;
}

jogador_t *le_jogadores(char *nome, int *njogadores)
{
    if (nome != NULL && njogadores != NULL)
    {
        FILE *arquivo = fopen(nome, "r");
        jogador_t *jogadores = (jogador_t *)malloc(sizeof(jogador_t) * (*njogadores));
        fseek(arquivo, sizeof(int), SEEK_SET);
        fread(jogadores, sizeof(jogador_t), (*njogadores), arquivo);
        fclose(arquivo);
        return jogadores;
    }
    return NULL;
}

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_jogos(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_idade(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_minutos(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statj_pontos(jogador_t *jogadores, int njogadores, char tipo)
{
}

int statt_soma_pontos(jogador_t *jogadores, int njogadores, char *time)
{
}

float statt_media_pontos(jogador_t *jogadores, int njogadores, char *time)
{
}

float statt_media_idade(jogador_t *jogadores, int njogadores, char *time)
{
}

int statt_posicao(jogador_t *jogadores, int njogadores, char *time, char *posicao)
{
}