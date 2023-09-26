#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int 			cestas;
	int 			arremessos;	
	float			percentual;
} arremessos_t;

typedef struct {
	char 			nome[128];
	int  			idade;
	char 			time[16];
	char 			posicao[8];		
	int  			jogos;
	int  			minutos;
	int 			pontos;
	
	arremessos_t 	a2;
	arremessos_t 	a3;
	arremessos_t 	aT;
	arremessos_t 	aL;	
} jogador_t;

int main() {
	FILE *f = fopen("jogadores.csv","r");

	char line[256];
	
	FILE *s = fopen("jogadores.dat","w+");

	int n = 442;

	fwrite(&n,sizeof(int),1,s);
	int i=1;
	while(fgets(line,256,f)) {
		jogador_t j;
		line[strlen(line)-1] = '\0';

		char *token = strtok(line,",");
		strcpy(j.nome,token); 			token = strtok(NULL,",");
		strcpy(j.posicao,token); 		token = strtok(NULL,",");
		j.idade = atoi(token); 			token = strtok(NULL,",");
		strcpy(j.time,token); 			token = strtok(NULL,",");
		j.jogos = atoi(token); 			token = strtok(NULL,",");
		j.minutos = atoi(token); 		token = strtok(NULL,",");

		j.aT.cestas = atoi(token); 		token = strtok(NULL,",");
		j.aT.arremessos = atoi(token); 	token = strtok(NULL,",");
		j.aT.percentual = atof(token); 	token = strtok(NULL,",");

		j.a3.cestas = atoi(token); 		token = strtok(NULL,",");
		j.a3.arremessos = atoi(token); 	token = strtok(NULL,",");
		j.a3.percentual = atof(token); 	token = strtok(NULL,",");

		j.a2.cestas = atoi(token); 		token = strtok(NULL,",");
		j.a2.arremessos = atoi(token); 	token = strtok(NULL,",");
		j.a2.percentual = atof(token); 	token = strtok(NULL,",");

		j.aL.cestas = atoi(token); 		token = strtok(NULL,",");
		j.aL.arremessos = atoi(token); 	token = strtok(NULL,",");
		j.aL.percentual = atof(token); 	token = strtok(NULL,",");

		j.pontos = atoi(token); 		token = strtok(NULL,",");
		
		printf("%d %s %s %d %s %d %d %d %d %f %d %d %f %d %d %f %d\n",i,j.nome,j.posicao,j.idade,j.time,j.jogos,j.minutos,j.a2.arremessos,j.a2.cestas,j.a2.percentual,j.a3.arremessos,j.a3.cestas,j.a3.percentual,j.aL.arremessos,j.aL.cestas,j.aL.percentual,j.pontos);
		i++;
		fwrite(&j,sizeof(jogador_t),1,s);
	}
	fclose(f);
	fclose(s);	

	return 0;
}