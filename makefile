CC = gcc
ASM = nasm

prog: main.o 
	$(CC) -m32 -o prog main.o 

main.o: main.c
	$(CC) -c -m32 -Wall -O0 -g -o main.o main.c

clean:
	rm prog main.o 
