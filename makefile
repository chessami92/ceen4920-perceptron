# Which compiler to use.
cc=gcc -o

all: build

build: main.c
	gcc -o main main.c

clean:
	rm -f main
