#include <stdio.h>

int main(void)
{
  int n;
  int n1;
  int n2 = -1;
  int ver = 0;
  scanf("%i", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%i", &n1);

    if (n1 < n2)
    {
      ver = 1;
    }
    n2 = n1;
  }

  if (ver == 1)
  {
    printf("NAO");
  }
  else
  {
    printf("SIM");
  }
  return 0;
}