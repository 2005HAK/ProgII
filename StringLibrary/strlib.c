#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[] = "ola mundo1";
    char string2[] = "ola mundo2";
    char string3[] = "ola mundo3";
    int k;

    //testa tamanho
    int num = str_length(&string);

    printf("%i\n", num);

    num = str_length(&string2);

    printf("%i\n", num);
    //termina testa tamanho

    //testa duplicação
    char *strDuplicate = (char *) str_duplicate(&string);

    printf("%s", strDuplicate);

    free(strDuplicate);
    //termina testa duplicação

    //testa comparação
    printf("\n%i\n", str_compare(&string, &string2));
    //termina testa comparação 

    //testa reverse
    str_reverse(&string);

    printf("%s", string);

    printf("\n");
    //termina testa reverse

    //testa upper
    str_upper(&string);

    printf("%s", string);

    printf("\n");
    //termina testa upper

    //testa lower
    str_lower(&string);

    printf("%s", string);

    printf("\n");
    //termina testa lower

    //testa copy
    str_copy(&string, &string2);

    printf("%s", string);
    //termina testa copy

    //testa concatene
    char *strcat = (char *)str_concatenate(&string, &string2);

    printf("%s", strcat);

    printf("\n");
    
    free(strcat);
    //termina testa concatene   
    
    //testa count words
    printf("%i", str_count_words(&string2));
    //termina testa words

    return 0;
}

// FUNCIONA
int str_length(const char *str)
{
    if (str == NULL)
    {
        return -1;
    }
    else
    {
        int i;

        for (i = 0; str[i] != '\0'; i++){}
        return i;
    }
}

// FUNCIONA
char *str_duplicate(const char *str)
{
    if (str != NULL)
    {
        int tam = str_length(str),
            j;
        char *strDuplicate = (char *)malloc((2 * tam + 1) * sizeof(char));

        if (strDuplicate != NULL)
        {
            for (j = 0; j <= (2 * tam); j++)
            {
                if (j < tam)
                {
                    strDuplicate[j] = str[j];
                }
                else if ((j - tam) < tam)
                {
                    strDuplicate[j] = str[(j - tam)];
                }
                else
                {
                    strDuplicate[j] = '\0';
                }
            }
        }
        return strDuplicate;
    }
    else
    {
        return NULL;
    }
}

// FUNICONA. CONFERIR DENOVO
int str_compare(const char *stra, const char *strb)
{
    int tama = str_length(stra), tamb = str_length(strb), i;

    if (tama == tamb)
    {
        for (i = 0; i < str_length(stra); i++)
        {
            if (stra[i] < strb[i])
            {
                return -1;
            }
            else if (stra[i] > strb[i])
            {
                return 1;
            }
        }
        return 0;
    }
    else if (tama < tamb)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// FUNCIONA. TESTAR RETORNOS
int str_reverse(char *str)
{
    if (str != NULL)
    {
        int tam = str_length(str), i, cont = 1;
        char anterior;

        for (i = 0; i < (tam / 2); i++)
        {
            anterior = str[i];
            str[i] = str[tam - cont];
            str[tam - cont] = anterior;
            cont++;
        }
        return 1;
    }
    return 0;
}

// FUNCIONA. TESTAR RETORNOS
int str_upper(char *str)
{
    if (str != NULL)
    {
        int contUpper = 0, i;

        for (i = 0; i < str_length(str); i++)
        {
            if (str[i] > 96 && str[i] < 123)
            {
                str[i] -= 32;
                contUpper++;
            }
        }
        return contUpper;
    }
    return -1;
}

// FUNCIONA. TESTAR RETORNOS
int str_lower(char *str)
{
    if (str != NULL)
    {
        int contLower = 0, i;

        for (i = 0; i < str_length(str); i++)
        {
            if (str[i] > 64 && str[i] < 91)
            {
                str[i] += 32;
                contLower++;
            }
        }
        return contLower;
    }
    return -1;
}

// FUNCIONA. RETORNOS NÃO TESTADOS
int str_copy(char *dst, const char *src)
{
    int tamDst = str_length(dst), tamSrc = str_length(src), i, ver = 0;

    if (dst != NULL || src != NULL)
    {
        if (tamDst >= tamSrc)
        {
            for (i = 0; i < tamDst; i++)
            {
                if (src[i] != '\0' && ver == 0)
                {
                    dst[i] = src[i];
                }
                else if (ver == 0)
                {
                    dst[i] = src[i];
                    ver = 1;
                }
                else
                {
                    dst[i] = ' ';
                }
            }
            return 1;
        }
        return 0;
    }
    return -1;
}
// não funciona
char *str_concatenate(const char *stra, const char *strb)
{
    int tama = str_length(stra), tamb = str_length(strb), i;
    char *strConcat = (char *)malloc((tama + tamb + 1) * sizeof(char));

    for (i = 0; i < (tama + tamb + 1); i++)
    {
        if (i < tama)
        {
            strConcat[i] = stra[i];
        }
        else if ((i >= tama) && ((i - tama) < tamb))
        {
            strConcat[i] = strb[(i - tama)];
        }
        else
        {
            strConcat[i] = '\0';
        }
    }
    return strConcat;
}

// FUNCIONA
int str_find_first(const char *str, const char c)
{
    if (str != NULL)
    {
        int tamStr = str_length(str), i;

        for (i = 0; i < tamStr; i++)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
    return -1;
}

// FUNCIONA
int str_find_last(const char *str, const char c)
{
    if (str != NULL)
    {
        int tamStr = str_length(str), i;

        for (i = (tamStr - 1); i > 0; i--)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
    return -1;
}

// NÃO FUNCIONA
int str_count_words(const char *str)
{
    if (str != NULL)
    {
        int tam = str_length(str);

        if (str[0] == '\0')
        {
            return 0;
        }
        else
        {
            int i, countSpace = 0, j;

            for (i = 1; i < (tam - 1); i++)
            {
                if (str[i] == ' ' && (str[i - 1] != ' ' || str[i + 1] != ' '))
                {
                    countSpace++;
                    while (str[i + 1] == ' ')
                    {
                        i++;
                    }
                }
            }
            return (countSpace + 1);
        }
    }
    return -1;
}