#include "lab.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char arquivo[] = "arquivo-teste.txt";
    double *valores;
    int qtde, repeticao, posicao = 3;

    valores = le_valores(arquivo, &qtde);

    for (int i = 0; i < qtde; i++)
    {
        printf("%i\247 valor: %f\n", (i + 1), valores[i]);
    }

    printf("Quantidade de numeros: %i\n", qtde);

    printf("Maior valor: %f\n", maior(valores, qtde));

    printf("Menor valor: %f\n", menor(valores, qtde));

    printf("Media dos valores: %f\n", media(valores, qtde));

    printf("Desvio padr\306o dos valores: %f\n", desvio(valores, qtde));

    printf("Amplitude dos valores: %f\n", amplitude(valores, qtde));

    printf("Valor na posi\207\306o 4 dos valores: %f\n", valor(valores, qtde, posicao));

    printf("Valor que mais se repete: %f\n", repetido(valores, qtde, &repeticao));

    printf("Quantas vezes se repete: %i\n", repeticao);

    return 0;
}

FILE *abre_arquivo(const char *arquivo){
    if(arquivo != NULL){
        return fopen(arquivo,"r");
    }
    return NULL;
    
}

int fecha_arquivo(FILE *arq){
    if(arq != NULL){
        fclose(arq);
        return 0;
    }
    return 11;
}

double* le_valores(const char *arquivo, unsigned int *qtd_numeros){
    if(qtd_numeros == NULL) return NULL;
    FILE *recebe = abre_arquivo(arquivo);
    if(recebe != NULL){    
        int a = 0, i = 0;
        double *ptr, c;
        fscanf(recebe,"%lf",&c);
        while(!feof(recebe)){
            a++;
        fscanf(recebe,"%lf",&c);
        }
        *qtd_numeros = a;
        ptr = (double*)  malloc ( a * sizeof(double));
        fseek(recebe,0,SEEK_SET);
        fscanf(recebe,"%lf",&c);
        while(!feof(recebe)){
            ptr[i] = c;
        fscanf(recebe,"%lf",&c);
        i++;
        }
        fecha_arquivo(recebe);
        recebe = NULL;
        return (ptr);
    }
     *qtd_numeros = 0;
     return NULL;
}

double maior(double* valores, unsigned int qtd_numeros){
    if(valores != NULL){
        int i = 0;
        double a;
        a = valores[0];
        while(i != qtd_numeros){
            if(a < valores[i]) a = valores[i];
            i++;
        }
        return a;
    }
    else return HUGE_VAL;
}

double menor(double* valores, unsigned int qtd_numeros){
    if(valores != NULL){
        int i = 0;
        double a;
        a = valores[0];
        while(i != qtd_numeros){
            if(valores[i] < a){
                a = valores[i];
            } 
            i++;
        }
        return a;
    }
    else return HUGE_VAL;
}

double media(double* valores, unsigned int qtd_numeros){
    if(valores != NULL){
        double a, b;
        int i = 0;
        while(i != qtd_numeros){
            a += valores[i];
            i++;
        }
        b = (a/qtd_numeros);
        return b;
    }
    else return HUGE_VAL;
}

double desvio(double* valores, unsigned int qtd_numeros){
    if(valores != NULL){
        double b,  a = media(valores, qtd_numeros);
        b = a;
        int i = 0;
        while(i != qtd_numeros){
            a += ((valores[i] - b)*(valores[i] - b));
            i++;
        }
        a = sqrt((a/qtd_numeros));
        return a;
    }
    else return HUGE_VAL;
}

double amplitude(double* valores, unsigned int qtd_numeros){
    if(valores != NULL){
        int i = 0;
        float a,b,c;
        a = valores[i];
        b = valores[i];
        while(i != qtd_numeros){
            if(a < valores[i]) a = valores[i];
            if(b > valores[i]) b = valores [i];
            i++;
        }
        c = (a - b);
        return c;
    } 
    else return HUGE_VAL;
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
    if(valores != NULL && posicao > 0 && posicao < qtd_numeros){
        return valores[posicao];
    }
    else return HUGE_VAL;
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
    if(valores != NULL){
        double a, b;
        int i = 0, t = 0, cont1 = 0, cont2 = 0;
        a = valores[i];
        while(i != qtd_numeros){
            while(t != qtd_numeros){
                if (valores[t] == a) cont1++;
                t++;
            }
            if(cont2 < cont1){
                b = a;
                cont2 = cont1;
            }
            cont1 = 0;
            i++;
            t = 0;
            a = valores[i];
        }
        *qtd_repeticao = cont2;
        return b;
    }
    else{
        *qtd_repeticao = 0;
        return HUGE_VAL;
     }
}