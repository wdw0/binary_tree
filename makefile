all: Trabalho 

Trabalho: arvore.o parsing.o main.o
	gcc -o Trabalho main.o arvore.o parsing.o

main.o: main.c
	gcc -c main.c

arvore.o: arvore.c
	gcc -c arvore.c

parsing.o: parsing.c
	gcc -c parsing.c

run:
	./Trabalho

clean:
	rm -rf *.o