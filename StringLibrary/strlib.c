#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{/*
    char string[] = {'o', 'l', 'a', 'm', 'u', 'n', 'd', 'o', '1', '\0'};
    char string2[] = {'o', 'l', 'a', 'm', 'u', 'n', 'd', 'o', '2', '\0'};
    const char *ptr1 = &string[0];
    const char *ptr2 = &string2[0];

    int num = str_length(&string), k;

    printf("%i\n", num);

    num = str_length(&string2);

    printf("%i\n", num);
    
            char *strDuplicate = (char *)str_duplicate(&string);

            for (k = 0; k < str_length(strDuplicate); k++)
            {
                printf("%c", strDuplicate[k]);
            }

            printf("\n%i\n", str_compare(&string, &string2));

            str_reverse(&string);

            for (k = 0; k < str_length(string); k++)
            {
                printf("%c", string[k]);
            }

            printf("\n");

            str_upper(&string);

            for (k = 0; k < str_length(string); k++)
            {
                printf("%c", string[k]);
            }

            printf("\n");

            str_lower(&string);

            for (k = 0; k < str_length(string); k++)
            {
                printf("%c", string[k]);
            }

            printf("\n");

            str_copy(&string, &string2);

            for (k = 0; k < str_length(string); k++)
            {
                printf("%c", string[k]);
            }

            free(strDuplicate);

        char *cat = str_concatenate(ptr1, ptr2);

        num = str_length(cat);

    printf("%i\n", str_find_last(ptr1, 'm'));

        for (k = 0; k < str_length(cat); k++)
        {
            printf("%c", string[k]);
        }
    */
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

        for (i = 0; str[i] != '\0'; i++)
        {
        }

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
    int tama = str_length(stra),
        tamb = str_length(strb),
        i;

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
        int tam = str_length(str),
            i,
            cont = 1;

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
        int contUpper = 0,
            i;

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
        int contLower = 0,
            i;

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
    int tamDst = str_length(dst),
        tamSrc = str_length(src),
        i,
        ver = 0;

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
/*não funciona
char *str_concatenate(const char *stra, const char *strb)
{
    int tama = str_length(stra),
        tamb = str_length(strb),
        i;

    char *strConcat = (char *)malloc((tama + tamb + 1) * sizeof(char));

    for (i = 0; i < (tama + tamb + 1); i++)
    {
        if (i < tama)
        {
            strConcat[i] = stra[i];
        }else if (i >= tama && (i - tama) < tamb)
        {
            strConcat[i] = strb[(i - tama)];
        } else {
            strConcat[i] = '\0';
        }
    }

    return strConcat;
}*/

// FUNCIONA
int str_find_first(const char *str, const char c)
{
    if (str != NULL)
    {
        int tamStr = str_length(str),
            i;

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
        int tamStr = str_length(str),
            i;

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

/*
int str_count_words(const char *str)
{
}*/