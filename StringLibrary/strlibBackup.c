#include "strlib.h"
// FUNCIONA
int str_length(const char *str)
{
    int i;
    if (str == NULL)
        return -1;
    else
    {
        for (i = 0; str[i] != '\0'; i++){}
        return i;
    }
}
// FUNCIONA
char *str_duplicate(const char *str)
{
    int tam = str_length(str), j;
    char *strDuplicate = (char *)malloc((2 * tam + 1) * sizeof(char));

    if (str != NULL)
    {
        if (strDuplicate != NULL)
        {
            for (j = 0; j <= (2 * tam); j++)
            {
                if (j < tam)
                    strDuplicate[j] = str[j];
                else if ((j - tam) < tam)
                    strDuplicate[j] = str[(j - tam)];
                else
                    strDuplicate[j] = '\0';
            }
        }
        return strDuplicate;
    }
    return NULL;
}
// FUNCIONA.
int str_compare(const char *stra, const char *strb)
{
    int tama = str_length(stra), tamb = str_length(strb), i;

    if (tama == tamb)
    {
        for (i = 0; i < str_length(stra); i++)
        {
            if (stra[i] < strb[i])
                return -1;
            else if (stra[i] > strb[i])
                return 1;
        }
        return 0;
    }
    else if (tama < tamb)
        return -1;
    else
        return 1;
}

// FUNCIONA.
int str_reverse(char *str)
{
    int tam = str_length(str), i, cont = 1;
    char anterior;

    if (str != NULL)
    {
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
// FUNCIONA.
int str_upper(char *str)
{
    int contUpper = 0, i;

    if (str != NULL)
    {
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
// FUNCIONA.
int str_lower(char *str)
{
    int contLower = 0, i;

    if (str != NULL)
    {
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
// FUNCIONA.
int str_copy(char *dst, const char *src)
{
    int tamDst = str_length(dst), tamSrc = str_length(src), i, ver = 0;

    if (dst != NULL && src != NULL)
    {
        if (tamDst >= tamSrc)
        {
            for (i = 0; i < tamDst; i++)
            {
                if (src[i] != '\0' && ver == 0)
                    dst[i] = src[i];
                else if (ver == 0)
                {
                    dst[i] = src[i];
                    ver = 1;
                }
                else
                    dst[i] = ' ';
            }
            return 1;
        }
        return 0;
    }
    return -1;
}
// FUNCIONA
char *str_concatenate(const char *stra, const char *strb)
{
    int tama = (str_length(stra) != -1) ? str_length(stra) : 0,
        tamb = (str_length(strb) != -1) ? str_length(strb) : 0, i;
    char *strConcat = (char *)malloc((tama + tamb + 1) * sizeof(char));

    if (stra != NULL || strb != NULL)
    {
        for (i = 0; i < (tama + tamb + 1); i++)
        {
            if (i < tama)
                strConcat[i] = stra[i];
            else if ((i >= tama) && ((i - tama) < tamb))
                strConcat[i] = strb[(i - tama)];
            else
                strConcat[i] = '\0';
        }
        return strConcat;
    }
    return NULL;
}
// FUNCIONA
int str_find_first(const char *str, const char c)
{
    int tamStr = str_length(str), i;

    if (str != NULL)
    {
        for (i = 0; i < tamStr; i++)
        {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    return -1;
}
// FUNCIONA
int str_find_last(const char *str, const char c)
{
    int tamStr = str_length(str), i;

    if (str != NULL)
    {
        for (i = (tamStr - 1); i > 0; i--)
        {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    return -1;
}
// FUNCIONA
int str_count_words(const char *str)
{
    int tam = str_length(str), i, countSpace = 0;

    if (str != NULL)
    {
        for (i = 0; i < tam; i++)
        {
            if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
                countSpace++;
        }
        return countSpace;
    }
    return -1;
}