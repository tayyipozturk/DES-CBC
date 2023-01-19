build: des.c
	gcc -o des des.c -lm

run: des
	./des

all: build run
