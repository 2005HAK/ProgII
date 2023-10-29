all: aplicacao

aplicacao: tda_privado_racional.o tda_racional.o aplicacao.o
	gcc -o aplicacao aplicacao.o tda_privado_racional.o tda_racional.o

aplicacao.o:
	gcc -c aplicacao.c

tda_privado_racional.o:
	gcc -c tda_privado_racional.c 

tda_racional.o:
	gcc -c tda_racional.c

clean:
	rm *.o aplicacao
