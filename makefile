# Which compiler and options to use.
cc=gcc -o

all: build

build: main.c perceptron.c random.c
	$(cc) main main.c perceptron.c random.c

run: build
	./main.exe

test: perceptron_test.c perceptron.c random.c
	$(cc) perceptron_test perceptron_test.c perceptron.c random.c
	./perceptron_test

clean:
	rm -f *.exe *.stackdump
