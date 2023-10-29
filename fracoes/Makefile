all: aplicacao

aplicacao: fracao.o main.o
	gcc -o aplicacao main.o fracao.o

main.o:
	gcc -c main.c

fracao.o:
	gcc -c fracao.c 

clean:
	rm *.o aplicacao
