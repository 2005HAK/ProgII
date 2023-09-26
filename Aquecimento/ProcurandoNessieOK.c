#include <stdio.h>
#include <math.h>

int main(){

    int nLagos, i, j; 

    scanf("%i", &nLagos);

    int gridLagos[nLagos][2];

    for(i = 0; i < nLagos; i++){
        for(j = 0; j < 2; j++){
            scanf("%i", &gridLagos[i][j]);
        }
    }

    for(i = 0; i < nLagos; i++){
        int nSonares;

        nSonares = floor(gridLagos[i][0] / 3) * floor(gridLagos[i][1] / 3);
        
        printf("%i\n", nSonares);
    }
    return 0;
}