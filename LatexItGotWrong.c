#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[1000];
    int aspas = 0, tam = 0, i, j;

    while (fgets(palavra, 1000, stdin))
    {
        tam = strlen(palavra);
        for (i = 0; i <= tam; i++)
        {
            if (palavra[i] == '"' && aspas == 0)
            {
                palavra[i] = '`';
                strcat(palavra, " ");
                for (j = tam; j > i; j--)
                {
                    palavra[j] = palavra[j - 1];
                    palavra[j - 1] = ' ';
                }

                palavra[i] = '`';
                aspas = 1;
            }
            else if (palavra[i] == '"' && aspas == 1)
            {
                palavra[i] = 39;
                
                if (i == tam)
                {
                    palavra[i + 1] = 39;
                } else {
                    for (j = tam; j > i; j--)
                    {
                        palavra[j] = palavra[j - 1];
                        palavra[j - 1] = ' ';
                    }
                    palavra[i] = 39;
                }
                
                tam = strlen(palavra);
                aspas = 0;
            }
        }
        palavra[strlen(palavra) + 1] = '\0';
        printf("%s", palavra);
        memset(palavra, 0, tam);
    }
    return 0;
}