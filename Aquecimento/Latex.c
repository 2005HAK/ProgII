#include <stdio.h>
#include <string.h>

void moveString(int tam, char *palavra, int i);

int main()
{
    char palavra[1000];
    int aspas = 0;
    int tam = 0;

    while (fgets(palavra, sizeof palavra, stdin))
    {
        
        tam = strlen(palavra);
        for (int i = 0; i <= tam; i++)
        {
            if (palavra[i] == '"' && aspas == 0)
            {
                palavra[i] = '`';

                moveString(tam, palavra, i);

                palavra[i] = '`';
                aspas = 1;
            }
            else if (palavra[i] == '"' && aspas == 1)
            {
                palavra[i] = '\'';
                
                if (i == tam)
                {
                    strcat(palavra, "'");
                } else {
                    moveString(tam, palavra, i);
                    palavra[i] = '8';
                }
                
                aspas = 0;
            }
        }
        printf("%s", palavra);
        strcpy(palavra, "");
    }
    return 0;
}

void moveString(int tam, char *palavra, int i)
{
    for (int j = tam; j > i; j--)
    {
        palavra[j] = palavra[j - 1];
        palavra[j - 1] = ' ';
    }
}