#include <stdio.h>

int main()
{
    int l[10], c[10], i, j, w, cont;
    char mat[10][10];

    for (i = 0; i < 10; i++)
    {
        scanf("%i", &l[i]);
        scanf("%i", &c[i]);
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            cont = 0;
            for (w = 0; w < 10; w++)
            {
                if (l[w] == i && c[w] == j)
                {
                    mat[i][j] = '*';
                }
                else
                {
                    if ((i + 1) == l[w] && j == c[w])
                    {
                        cont++;
                    }
                    if ((i + 1) == l[w] && (j + 1) == c[w])
                    {
                        cont++;
                    }
                    if (i == l[w] && (j + 1) == c[w])
                    {
                        cont++;
                    }
                    if ((i - 1) == l[w] && (j + 1) == c[w])
                    {
                        cont++;
                    }
                    if ((i - 1) == l[w] && j == c[w])
                    {
                        cont++;
                    }
                    if ((i - 1) == l[w] && (j - 1) == c[w])
                    {
                        cont++;
                    }
                    if (i == l[w] && (j - 1) == c[w])
                    {
                        cont++;
                    }
                    if ((i + 1) == l[w] && (j - 1) == c[w])
                    {
                        cont++;
                    }
                }
            }
            if (mat[i][j] != '*')
            {
                mat[i][j] = cont + '0';
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == 9)
            {
                printf("%c", mat[i][j]);
            }
            else
            {
                printf("%c ", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}