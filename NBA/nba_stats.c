#include "nba_stats.h"

int le_cabecario(char *nome){
    int tamanho;
    if (nome != NULL){
        FILE *arquivo = fopen(nome, "rb");
        if (arquivo != NULL){
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
        if(*njogadores != 0){
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
    return NULL;
}

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo){
    int i, indice = 0;
    if (jogadores != NULL){
        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a2.arremessos < jogadores[i].a2.arremessos) indice = i;
                break;
            case '3':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a3.arremessos < jogadores[i].a3.arremessos) indice = i;
                break;
            case 'T':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aT.arremessos < jogadores[i].aT.arremessos) indice = i;
                break;
            case 'L':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aL.arremessos < jogadores[i].aL.arremessos) indice = i;
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
    int i, indice = 0;
    if (jogadores != NULL){
        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a2.cestas < jogadores[i].a2.cestas) indice = i;
                break;
            case '3':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a3.cestas < jogadores[i].a3.cestas) indice = i;
                break;
            case 'T':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aT.cestas < jogadores[i].aT.cestas) indice = i;
                break;
            case 'L':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aL.cestas < jogadores[i].aL.cestas) indice = i;
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}
//ta estranho
int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo){
    int i, indice = 0;
    if (jogadores != NULL){
        switch (tipo){
            case '2':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a2.percentual < jogadores[i].a2.percentual) indice = i;
                break;
            case '3':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].a3.percentual < jogadores[i].a3.percentual) indice = i;
                break;
            case 'T':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aT.percentual < jogadores[i].aT.percentual) indice = i;
                break;
            case 'L':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].aL.percentual < jogadores[i].aL.percentual) indice = i;
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
    int indice = 0, i;
    if (jogadores != NULL){
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].jogos < jogadores[i].jogos) indice = i;
                break;
            case '-':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].jogos > jogadores[i].jogos) indice = i;
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
    int indice = 0, i;
    if (jogadores != NULL){
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].idade < jogadores[i].idade) indice = i;
                break;
            case '-':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].idade > jogadores[i].idade) indice = i;
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
    int indice = 0, i;
    if (jogadores != NULL){
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].minutos < jogadores[i].minutos) indice = i;
                break;
            case '-':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].minutos > jogadores[i].minutos) indice = i;
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
    int indice = 0, i;
    if (jogadores != NULL){
        switch (tipo){
            case '+':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].pontos < jogadores[i].pontos) indice = i;
                break;
            case '-':
                for (i = 0; i < njogadores; i++) if (jogadores[indice].pontos > jogadores[i].pontos) indice = i;
                break;
            default:
                return -2;
                break;
        }
        return indice;
    }
    return -1;
}
//aparentemente errado
int statt_soma_pontos(jogador_t *jogadores, int njogadores, char *time){
    int somaPontos = 0, i;
    if (jogadores != NULL && time != NULL){ 
        for (i = 0; i < njogadores; i++) if (strcmp(jogadores[i].time, time) == 0) somaPontos += jogadores[i].pontos;
        return somaPontos;
    }
    return -1;
}

float statt_media_pontos(jogador_t *jogadores, int njogadores, char *time){
    float somaPontos = 0, qtdJogadores = 0;
    int i;
    if (jogadores != NULL && time != NULL){
        for (i = 0; i < njogadores; i++)
            if (strcmp(jogadores[i].time, time) == 0){
                somaPontos += jogadores[i].pontos;
                qtdJogadores++;
            }
        return (somaPontos == 0 && qtdJogadores == 0) ? 0 : (somaPontos / qtdJogadores);
    }
    return -1;
}

float statt_media_idade(jogador_t *jogadores, int njogadores, char *time){
    float somaIdade = 0, qtdJogadores = 0;
    int i;
    if (jogadores != NULL && time != NULL){
        for (i = 0; i < njogadores; i++)
            if (strcmp(jogadores[i].time, time) == 0){
                somaIdade += jogadores[i].idade;
                qtdJogadores++;
            }
        return (somaIdade == 0 && qtdJogadores == 0) ? 0 : (somaIdade / qtdJogadores);
    }
    return -1;
}

int statt_posicao(jogador_t *jogadores, int njogadores, char *time, char *posicao){
    int qtdJogadores = 0, i;
    if (jogadores != NULL && time != NULL && posicao != NULL){
        for (i = 0; i < njogadores; i++) if (strcmp(jogadores[i].time, time) == 0) if (strcmp(jogadores[i].posicao, posicao) == 0) qtdJogadores++;
        return qtdJogadores;
    }
    return -1;
}