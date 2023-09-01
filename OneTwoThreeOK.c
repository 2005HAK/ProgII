#include <stdio.h>
#include <string.h>

int main(void)
{

  int cont;
  char palavra[20];
  int cont1 = 0;
  int cont2 = 0;
  char p1[] = "one";
  char p2[] = "two";

  scanf("%i", &cont);

  for (int i = 0; i < cont; i++)
  {

    scanf("%s", palavra);
    if (strlen(palavra) == 5)
    {
      printf("3\n");
    }
    else
    {
      for (int j = 0; j < 3; j++)
      {
        if (palavra[j] == p1[j])
        {
          cont1++;
        }

        if (palavra[j] == p2[j])
        {
          cont2++;
        }
      }

      if (cont1 > cont2)
      {
        printf("1\n");
      }
      else
      {
        printf("2\n");
      }

      cont1 = 0;
      cont2 = 0;
    }
  }
  return 0;
}