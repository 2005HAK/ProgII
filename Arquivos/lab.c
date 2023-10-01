#include "lab.h"
#include <stdlib.h>
#include <math.h>

// FUNCIONA
FILE *abre_arquivo(const char *arquivo)
{
    FILE *arquivoOpen = fopen(arquivo, "r");

    return arquivoOpen;
}
// FUNCIONA
int fecha_arquivo(FILE *arq)
{
    return fclose(arq);
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros)
{
    float valor;
    int qtde = 0, i;
    FILE *arquivoAberto = abre_arquivo(arquivo);

    if (arquivoAberto != NULL)
    {
        fscanf(arquivoAberto, "%f", &valor);

        for (qtde; !feof(arquivoAberto); qtde++)
            fscanf(arquivoAberto, "%f", &valor);

        double *vetValores = (double *)malloc(sizeof(double) * qtde);

        fseek(arquivoAberto, 0, SEEK_SET);

        fscanf(arquivoAberto, "%f", &valor);

        for (i = 0; i < qtde; i++)
        {
            vetValores[i] = valor;
            fscanf(arquivoAberto, "%f", &valor);
        }

        *qtd_numeros = qtde;
        return vetValores;
    }

    *qtd_numeros = 0;
    return NULL;
}

double maior(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
    {
        double maior = valores[0];
        int i;

        for (i = 1; i < qtd_numeros; i++)
        {
            if (valores[i] > maior)
                maior = valores[i];
        }

        return maior;
    }

    return HUGE_VAL;
}

double menor(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
    {
        double menor = valores[0];
        int i;

        for (i = 1; i < qtd_numeros; i++)
        {
            if (valores[i] < menor)
                menor = valores[i];
        }

        return menor;
    }

    return HUGE_VAL;
}

double media(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
    {
        int i;
        double soma = 0;

        for (i = 0; i < qtd_numeros; i++)
            soma += valores[i];

        return (soma / qtd_numeros);
    }

    return HUGE_VAL;
}

double desvio(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
    {
        double mediaDosValores = media(valores, qtd_numeros), somaDesvios = 0;
        int i;

        for (i = 0; i < qtd_numeros; i++)
        {
            somaDesvios += pow((valores[i] - mediaDosValores), 2);
        }

        return (sqrt(somaDesvios / qtd_numeros));
    }

    return HUGE_VAL;
}

double amplitude(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
    {
        return (maior(valores, qtd_numeros) - menor(valores, qtd_numeros));
    }

    return HUGE_VAL;
}

double valor(double *valores, unsigned int qtd_numeros, unsigned int posicao)
{
    if ((valores != NULL) && (posicao >= qtd_numeros))
    {
        return (valores[posicao]);
    }

    return HUGE_VAL;
}

double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao)
{
    if (valores != NULL)
    {
        double *valoresRep = (double *)malloc(sizeof(double) * qtd_numeros), valorRep;
        int *repeticoes = (int *)calloc(qtd_numeros, sizeof(int)), i, j, w = 0, ver = 0, maior = 0, pos = 0;

        for (i = 0; i < qtd_numeros; i++)
        {
            for (j = 0; j < qtd_numeros; j++)
            {
                if (valores[i] == valoresRep[j])
                    ver = 1;
            }

            if (ver == 0)
            {
                valoresRep[w] = valores[i];
                w++;
            }
        }

        for (i = 0; i < (w + 1); i++)
        {
            for (j = 0; j < qtd_numeros; j++)
            {
                if (valores[j] == valoresRep[i])
                    repeticoes[i]++;
            }
        }

        for (i = 0; i < (w + 1); i++)
        {
            if (repeticoes[i] > maior)
            {
                maior = repeticoes[i];
                pos = i;
            }
        }

        *qtd_repeticao = maior;
        valorRep = valoresRep[pos];

        free(valoresRep);
        free(repeticoes);

        return valorRep;
    }

    *qtd_repeticao = 0;
    return HUGE_VAL;
}