#include <stdio.h>

int main()
{
    int ver = 0, vet[4], i, graus = 1080;

    while (1)
    {
        graus = 1080;
        ver = 0;

        for (i = 0; i < 4; i++)
        {
            scanf("%i", &vet[i]);

            if (vet[i] == 0)
                ver++;
        }

        if (ver == 4)
            break;

        for (i = 1; i < 4; i++)
        {
            if (vet[i] != vet[i - 1])
            {
                if (i == 2)
                {
                    if (vet[i] > vet[i - 1])
                    {
                        graus += (((vet[i] - vet[i - 1])) * 360) / 40;
                    }
                    else
                    {
                        graus += ((40 - (vet[i - 1] - vet[i])) * 360) / 40;
                    }
                }
                else
                {
                    if (vet[i] > vet[i - 1])
                    {
                        graus += ((40 - (vet[i] - vet[i - 1])) * 360) / 40;
                    }
                    else
                    {
                        graus += (((vet[i - 1] - vet[i])) * 360) / 40;
                    }
                }
            }
        }
        printf("%i\n", graus);
    }
    return 0;
}