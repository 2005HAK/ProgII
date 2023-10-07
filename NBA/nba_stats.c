#include "nba_stats.h"

int le_cabecario(char *nome){
    if (nome != NULL)    {
        FILE *arquivo = fopen(nome, "rb");
        if (arquivo != NULL)        {
            int tamanho;
            fread(&tamanho, sizeof(int), 1, arquivo);
            fclose(arquivo);
            arquivo = NULL;
            return tamanho;
        }
        return 0;
    }
    return -1;
}

jogador_t *le_jogadores(char *nome, int *njogadores){
    if (nome != NULL && njogadores != NULL){
        *njogadores = le_cabecario(nome);
        FILE *arquivo = fopen(nome, "rb");
        jogador_t *jogadores = (jogador_t *)malloc((*njogadores) * sizeof(jogador_t));
        fseek(arquivo, sizeof(int), SEEK_SET);
        fread(jogadores, sizeof(jogador_t), (*njogadores), arquivo);

        fclose(arquivo);
        arquivo = NULL;
        return jogadores;
    }
    return NULL;
}

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int i, maior = 0, indice = 0;

        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a2.arremessos){
                        maior = jogadores[i].a2.arremessos;
                        indice = i;
                    }
                break;
            case '3':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a3.arremessos){
                        maior = jogadores[i].a3.arremessos;
                        indice = i;
                    }
                break;
            case 'T':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aT.arremessos){
                        maior = jogadores[i].aT.arremessos;
                        indice = i;
                    }
                break;
            case 'L':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aL.arremessos){
                        maior = jogadores[i].aL.arremessos;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int i, maior = 0, indice = 0;

        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a2.cestas){
                        maior = jogadores[i].a2.cestas;
                        indice = i;
                    }
                break;
            case '3':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a3.cestas){
                        maior = jogadores[i].a3.cestas;
                        indice = i;
                    }
                break;
            case 'T':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aT.cestas){
                        maior = jogadores[i].aT.cestas;
                        indice = i;
                    }
                break;
            case 'L':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aL.cestas){
                        maior = jogadores[i].aL.cestas;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int i, maior = 0, indice = 0;

        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a2.percentual){
                        maior = jogadores[i].a2.percentual;
                        indice = i;
                    }
                break;
            case '3':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].a3.percentual){
                        maior = jogadores[i].a3.percentual;
                        indice = i;
                    }
                break;
            case 'T':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aT.percentual){
                        maior = jogadores[i].aT.percentual;
                        indice = i;
                    }
                break;
            case 'L':
                for (i = 0; i < njogadores; i++)
                    if (maior < jogadores[i].aL.percentual){
                        maior = jogadores[i].aL.percentual;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_jogos(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int indice = 0, numJogos = jogadores[0].jogos, i;
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++)
                    if (numJogos < jogadores[i].jogos){
                        numJogos = jogadores[i].jogos;
                        indice = i;
                    }
                break;
            case '-':
                for (i = 0; i < njogadores; i++)
                    if (numJogos > jogadores[i].jogos){
                        numJogos = jogadores[i].jogos;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_idade(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int indice = 0, idade = jogadores[0].idade, i;
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++)
                    if (idade < jogadores[i].idade){
                        idade = jogadores[i].idade;
                        indice = i;
                    }
                break;
            case '-':
                for (i = 0; i < njogadores; i++)
                    if (idade > jogadores[i].idade){
                        idade = jogadores[i].idade;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_minutos(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int indice = 0, minutos = jogadores[0].minutos, i;
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++)
                    if (minutos < jogadores[i].minutos){
                        minutos = jogadores[i].minutos;
                        indice = i;
                    }
                break;
            case '-':
                for (i = 0; i < njogadores; i++)
                    if (minutos > jogadores[i].minutos){
                        minutos = jogadores[i].minutos;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statj_pontos(jogador_t *jogadores, int njogadores, char tipo){
    if (jogadores != NULL){
        int indice = 0, pontos = jogadores[0].pontos, i;
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++)
                    if (pontos < jogadores[i].pontos){
                        pontos = jogadores[i].pontos;
                        indice = i;
                    }
                break;
            case '-':
                for (i = 0; i < njogadores; i++)
                    if (pontos > jogadores[i].pontos){
                        pontos = jogadores[i].pontos;
                        indice = i;
                    }
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}

int statt_soma_pontos(jogador_t *jogadores, int njogadores, char *time){
    if (jogadores != NULL && time != NULL){
        int somaPontos = 0, i;
        for (i = 0; i < njogadores; i++) if (strcmp(jogadores[i].time, time) == 0) somaPontos += jogadores[i].pontos;
        return somaPontos;
    }
    return -1;
}

float statt_media_pontos(jogador_t *jogadores, int njogadores, char *time){
    if (jogadores != NULL && time != NULL){
        float somaPontos = 0, qtdJogadores = 0;
        int i;
        for (i = 0; i < njogadores; i++)
            if (strcmp(jogadores[i].time, time) == 0){
                somaPontos += jogadores[i].pontos;
                qtdJogadores++;
            }
        return (somaPontos / qtdJogadores);
    }
    return -1;
}

float statt_media_idade(jogador_t *jogadores, int njogadores, char *time){
    if (jogadores != NULL && time != NULL){
        float somaIdade = 0, qtdJogadores = 0;
        int i;
        for (i = 0; i < njogadores; i++)
            if (strcmp(jogadores[i].time, time) == 0){
                somaIdade += jogadores[i].idade;
                qtdJogadores++;
            }
        return (somaIdade / qtdJogadores);
    }
    return -1;
}

int statt_posicao(jogador_t *jogadores, int njogadores, char *time, char *posicao){
    if (jogadores != NULL && time != NULL && posicao != NULL){
        int qtdJogadores = 0, i;
        for (i = 0; i < njogadores; i++) if (strcmp(jogadores[i].time, time) == 0) if (strcmp(jogadores[i].posicao, posicao) == 0) qtdJogadores++;
        return qtdJogadores;
    }
    return -1;
}