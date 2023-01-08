all: listaxor.o proy2.o
		gcc -g listaxor.o proy2.o -o proy2

listaxor.o: listaxor.c
		gcc -c listaxor.c -o listaxor.o

proy2.o: proy2.c
		gcc -c proy2.c -o proy2.o