#include <stdio.h>

int main(void) {
  int nCaixas, i, j;

  scanf("%i", &nCaixas);
  int val[nCaixas][3], vet[nCaixas];

  for(i = 0; i < nCaixas; i++){
    for(j = 0; j < 3; j++){
      scanf("%i", &val[i][j]);

      if(val[i][j] > 20){
        vet[i] = 1;
      } else {
        if(vet[i] != 1){
          vet[i] = 0;
        } 
      }
    }
  }

  for(i = 0; i < nCaixas; i++){
    if(vet[i] == 1){
      printf("Caso %i: bad\n", (i + 1));
    } else {
      printf("Caso %i: good\n", (i + 1));
    }
  }
  return 0;
}