all: build run
build:
	gcc main.c -Wall -o main
run: 
	./main
