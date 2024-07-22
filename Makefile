all: build run
build:
	gcc src/*.c -Wall -o main
run: 
	./main
