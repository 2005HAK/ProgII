#include "lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Abre o arquivo cujo nome eh recebido por parametro ("arquivo") para leitura.
 * Retorna um ponteiro para o arquivo aberto.
 */
FILE *abre_arquivo(const char *arquivo)
{
    if (arquivo == NULL)
    {
        return NULL;
    }
    return fopen(arquivo, "r");
}
/*
 * Fecha o arquivo recebido por parametro.
 * Retorna 0 caso consiga fechar o arquivo, qualquer outro valor caso contrario.
 */
int fecha_arquivo(FILE *arq)
{
    if (arq == NULL)
    {
        return 27;
    }
    fclose(arq);
    return 0;
}
/*
 * Le os valores que estao dentro do "arquivo" e retorna um vetor contendo os valores.
 * Retorna dentro de "qtd_numeros" a quantidade de nÃºmeros existentes dentro do arquivo lido.
 * Caso nÃ£o for possÃ­vel ler o arquivo, "qtd_numeros" deve conter ZERO e retornar a constante NULL.
 * Se "qtd_numeros" for invalido, a leitura deve ser invalidade e retornar a constante NULL.
 */
double *le_valores(const char *arquivo, unsigned int *qtd_numeros)
{
    if (qtd_numeros == NULL)
    {
        return NULL;
    }
    if (arquivo == NULL)
    {
        *qtd_numeros = 0;
        return NULL;
    }
    FILE *arq;
    arq = abre_arquivo(arquivo);

    if (arq == NULL)
    {
        *qtd_numeros = 0;
        fecha_arquivo(arq);
        return NULL;
    }

    unsigned int i = 0, valores = 0;

    double u;

    while (fscanf(arq, "%lf", &u) == 1)
    {
        valores++;
    }
    *qtd_numeros = valores;
    double *leitura;
    leitura = (double *)malloc((valores) * sizeof(double));

    if (leitura == NULL)
    {
        *qtd_numeros = 0;
        free(leitura);
        return NULL;
    }

    rewind(arq);

    while (i < *qtd_numeros)
    {
        fscanf(arq, "%lf", &leitura[i]);
        i++;
    }
    fecha_arquivo(arq);
    return leitura;
}

/*
 * Essa funÃ§Ã£o retorna o maior valor presente no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h)
 * */
double maior(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    printf("aqui foi");
    double maior = 0;
    maior = valores[0];
    unsigned int i;
    for (i = 0; i < qtd_numeros; i++)
    {
        if (valores[i] > maior)
        {
            maior = valores[i];
        }
    }
    return maior;
}

/*
 * Essa funÃ§Ã£o retorna o menor valor presente no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h)
 * */
double menor(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    double menor = 0;
    menor = valores[0];
    unsigned int i;
    for (i = 0; i < qtd_numeros; i++)
    {
        if (valores[i] < menor)
        {
            menor = valores[i];
        }
    }
    return menor;
}

/*
 * Essa funÃ§Ã£o retorna a mÃ©dia dos valores presentes no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h)
 * */
double media(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    double soma = 0, media = 0;
    unsigned int i;
    for (i = 0; i < qtd_numeros; i++)
    {
        soma += valores[i];
    }
    media = soma / qtd_numeros;
    return media;
}

/*
 * Essa funÃ§Ã£o retorna o desvio padrÃ£o dos valores presentes no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h)
 * */
double desvio(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    unsigned int i;
    double media_d, soma_variancia = 0, variancia = 0, desvio = 0, val = 0;
    media_d = media(valores, qtd_numeros);
    for (i = 0; i < qtd_numeros; i++)
    {
        val = pow((valores[i] - media_d), 2);
        soma_variancia += val;
    }
    variancia = soma_variancia / (qtd_numeros - 1);
    desvio = sqrt(variancia);
    return desvio;
}

/*
 * Essa funÃ§Ã£o retorna a amplitude(diferenÃ§a entre o maior e o menor nÃºmero) dos valores presentes no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h)
 * */
double amplitude(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    double menor_a, maior_a, amp;
    menor_a = menor(valores, qtd_numeros);
    maior_a = maior(valores, qtd_numeros);
    amp = maior_a - menor_a;
    return amp;
}

/*
 * Essa funÃ§Ã£o retorna o valor que estÃ¡ localizado em uma "posicao" do array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h).
 * Caso for posiÃ§Ã£o invalida, retorna a constante HUGE_VAL (em math.h).
 * */
double valor(double *valores, unsigned int qtd_numeros, unsigned int posicao)
{
    if (valores == NULL || qtd_numeros == 0)
    {
        return HUGE_VAL;
    }
    if (posicao > qtd_numeros - 1)
    {
        return HUGE_VAL;
    }
    double valor_posicao = 0;
    valor_posicao = valores[posicao];
    return valor_posicao;
}

/*
 * Essa funÃ§Ã£o retorna o nÃºmero que mais se repete e quantas vezes ele aparece (em caso de igualdade, o primeiro encontrado tem preferÃªncia) no array.
 * Retorna dentro de "qtd_repeticao" a quantidade de vezes que o determinado nÃºmero se repete no array.
 * Caso for um array invÃ¡lido, retorna a constante HUGE_VAL (em math.h) e ZERO em "qtd_repeticao".
 */
double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao)
{
    if (valores == NULL || qtd_numeros == 0 || qtd_repeticao == NULL)
    {
        if (qtd_repeticao != NULL)
        {
            *qtd_repeticao = 0;
        }
        return HUGE_VAL;
    }

    double mais_rep = valores[0];
    unsigned int max_rep = 0, contador;

    for (unsigned int i = 0; i < qtd_numeros; i++)
    {
        double repetida = valores[i];
        contador = 0;
        for (unsigned int j = 0; j < qtd_numeros; j++)
        {
            if (repetida == valores[j])
            {
                contador++;
            }
        }
        if (contador > max_rep)
        {
            max_rep = contador;
            mais_rep = repetida;
        }
    }
    *qtd_repeticao = max_rep;
    return mais_rep;
}

///////    MEU CODIGO    /////////////////////////////////////////////////////////////////////////

// FUNCIONA
FILE *abre_arquivo(const char *arquivo)
{
    if (arquivo != NULL)
        return fopen(arquivo, "r");
    return NULL;
}
// FUNCIONA
int fecha_arquivo(FILE *arq)
{
    if (arq != NULL)
    {
        fclose(arq);
        return 0;
    }

    return 1;
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros)
{
    if (qtd_numeros == NULL)
    {
        return NULL;
    }

    FILE *arquivoAberto = abre_arquivo(arquivo);

    if (arquivoAberto != NULL)
    {
        double valor;
        int qtde = 0, i;

        fscanf(arquivoAberto, "%lf", &valor);

        for (qtde; !feof(arquivoAberto); qtde++)
            fscanf(arquivoAberto, "%lf", &valor);

        *qtd_numeros = qtde;

        double *vetValores = (double *)malloc(sizeof(double) * qtde);

        fseek(arquivoAberto, 0, SEEK_SET);

        fscanf(arquivoAberto, "%lf", &valor);

        for (i = 0; i < qtde; i++)
        {
            vetValores[i] = valor;
            fscanf(arquivoAberto, "%lf", &valor);
        }

        fecha_arquivo(arquivoAberto);
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
            somaDesvios += pow((valores[i] - mediaDosValores), 2);

        return (sqrt(somaDesvios / qtd_numeros));
    }

    return HUGE_VAL;
}

double amplitude(double *valores, unsigned int qtd_numeros)
{
    if (valores != NULL)
        return (maior(valores, qtd_numeros) - menor(valores, qtd_numeros));

    return HUGE_VAL;
}

double valor(double *valores, unsigned int qtd_numeros, unsigned int posicao)
{
    if ((valores != NULL) && (posicao < qtd_numeros))
        return (valores[posicao]);

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