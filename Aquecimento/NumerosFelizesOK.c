#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s1, soma, entradas, i, j, w;

    scanf("%i", &entradas);
    int so[entradas];

    for (i = 0; i < entradas; i++)
    {
        scanf("%i", &so[i]);
    }

    for (i = 0; i < entradas; i++)
    {
        s1 = so[i];

        while (soma != 1 && soma != so[i] && soma != 37)
        {
            soma = 0;
            for (j = 10, w = 1; j <= 1000000000; j *= 10, w *= 10)
            {
                int valor = (s1 % j) / w;
                soma += valor * valor;
            }
            s1 = soma;
        }

        if (soma == 1)
        {
            printf("Entrada #%i: %i e um numero feliz.\n", (i + 1), so[i]);
        }
        else
        {
            printf("Entrada #%i: %i e um numero infeliz.\n", (i + 1), so[i]);
        }
        
        soma = 0;
    }
    
    return 0;
}