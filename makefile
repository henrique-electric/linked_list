all: list.o
	gcc list.o main.c -o main
	./main

list.o: list.c
	gcc -c list.c
