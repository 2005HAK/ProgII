#include <stdio.h>

int main() {
  int tam, i, j, valores[2], contL = 0, contC = 0;

  scanf("%i", &tam);
  
  while(tam != 0){
    
    int mat[tam][tam], l[tam], c[tam];

    for(i = 0; i < tam; i++){
      l[i] = 0;
      c[i] = 0;
      for(j = 0; j < tam; j++){
        scanf("%i", &mat[i][j]);    
        l[i] += mat[i][j];
      }
      if((l[i] % 2) != 0){
        valores[0] = i;
        contL++;
      }
    }

    for(i = 0; i < tam; i++){
      for(j = 0; j < tam; j++){
        c[i] += mat[j][i];
      }
      if((c[i] % 2) != 0){
        valores[1] = i;
        contC++;
      }
    }      

    if(contL == 0 && contC == 0){
      printf("OK\n");
    } else if(contL == 1 && contC == 1){
      printf("Troque o bit (%i,%i)\n", (valores[0] + 1), (valores[1] + 1));
    } else {
      printf("Corrompido\n");
    }
    contL = 0;
    contC = 0;
    scanf("%i", &tam);  
  }
  return 0;
}