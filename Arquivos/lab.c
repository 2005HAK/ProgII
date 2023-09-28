#include "lab.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    char arq[] = "arquivo-teste.txt";
    int num = 0;
    int *qtdeNumeros = &num, i;
    double *vetor;
    FILE *arquivoAberto = fopen("arquivo-teste.txt", "r");
   
    vetor = le_valores(arquivoAberto, qtdeNumeros);

    printf("%f ", media(vetor, *qtdeNumeros));
    printf("%i ", num);

    fclose(arquivoAberto);

    return 0;
}
//FUNCIONA
FILE *abre_arquivo(const char *arquivo){

    FILE *arquivoOpen = fopen(arquivo, "r");

    return arquivoOpen;
}
//FUNCIONA
int fecha_arquivo(FILE *arq){
    return fclose(arq);
}
//FUNCIONA
double *le_valores(FILE *arquivo, unsigned int *qtd_numeros){
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
//FUNCIONA
double maior(double *valores, unsigned int qtd_numeros){
    double maior = valores[0];
    int i;

    for(i = 1; i < qtd_numeros; i++){
        if(valores[i] > maior) maior = valores[i];
    }

    return maior;
}
//FUNCIONA
double menor(double *valores, unsigned int qtd_numeros){
    double menor = valores[0];
    int i;

    for(i = 1; i < qtd_numeros; i++){
        if(valores[i] < menor) menor = valores[i];
    }

    return menor;
}
//FUNCIONA
double media(double *valores, unsigned int qtd_numeros){
    int i;
    double soma = 0;

    for(i = 0; i < qtd_numeros; i++){
        soma += valores[i];
    }

    return (soma/qtd_numeros);
}
//testar retorno
double desvio(double *valores, unsigned int qtd_numeros){
    double mediaDosValores = media(valores, qtd_numeros), somaDesvios = 0;
    int i;

    for(i = 0; i < qtd_numeros; i++){
        somaDesvios += pow((valores[i] - mediaDosValores), 2);
    }

    return sqrt(somaDesvios / qtd_numeros);
}
//FUNCIONA
double amplitude(double *valores, unsigned int qtd_numeros){
    if(valores == NULL) return HUGE_VAL;

    return (maior(valores, qtd_numeros) - menor(valores, qtd_numeros));
}
//FUNCIONA
double valor(double *valores, unsigned int qtd_numeros, unsigned int posicao){
    if(valores == NULL) return HUGE_VAL;

    if(posicao >= qtd_numeros) return HUGE_VAL;

    return (valores[posicao]);
}

double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
    if(valores == NULL){
        *qtd_repeticao = 0;
        return HUGE_VAL;
    }
    /*
    implementar logica para verificar os valores
    */
}