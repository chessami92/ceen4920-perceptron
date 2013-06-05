# Which compiler to use.
cc=gcc -o

all: build

build: main.c perceptron.c
	gcc -o main main.c perceptron.c

test: perceptron_test.c perceptron.c
	gcc -o perceptron_test perceptron_test.c perceptron.c
	./perceptron_test

clean:
	rm -f main perceptron_test
