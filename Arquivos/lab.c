#include "lab.h"
#include <string.h>
#include <stdlib.h>

int main()
{

    char arq[] = "arquivo-teste.txt";
    int num = 0;
    int *qtdeNumeros = &num, i;
    double *vetor;
    FILE *arquivoAberto = abre_arquivo(arq);
    vetor = le_valores(arquivoAberto, qtdeNumeros);
    maior(vetor, *qtdeNumeros);
    return 0;
}
//FUNCIONA
FILE *abre_arquivo(const char *arquivo)
{

    FILE *arquivoOpen = fopen(arquivo, "r");

    return arquivoOpen;
}
//FUNCIONA
int fecha_arquivo(FILE *arq)
{
    return fclose(arq);
}
//FUNCIONA
double *le_valores(FILE *arquivo, unsigned int *qtd_numeros)
{
    float valor;
    int qtde = 0, i; 
    fscanf(arquivo, "%f", &valor);

    for(qtde; !feof(arquivo); qtde++) fscanf(arquivo, "%f", &valor);

    double *vetValores = (double *)malloc(sizeof(double) * qtde);

    fseek(arquivo, 0, SEEK_SET);

    fscanf(arquivo, "%f", &valor);

    for(i = 0; i < qtde; i++){
        vetValores[i] = valor;
        fscanf(arquivo, "%f", &valor);
    }
    
    *qtd_numeros = qtde;
    return vetValores;
}

double maior(double *valores, unsigned int qtd_numeros)
{
    
}

double menor(double *valores, unsigned int qtd_numeros)
{
}

double media(double *valores, unsigned int qtd_numeros)
{
}

double desvio(double *valores, unsigned int qtd_numeros)
{
}

double amplitude(double *valores, unsigned int qtd_numeros)
{
}

double valor(double *valores, unsigned int qtd_numeros, unsigned int posicao)
{
}

double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao)
{
}