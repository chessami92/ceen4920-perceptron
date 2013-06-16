#include <stdio.h>
#include <string.h>
#include <math.h>

#define PERCEPTRON_INPUTS 5

#include "perceptron.h"

float nextValue( void ) {
    static float time = -0.01;
    time += 0.01;
    return sin( 2 * M_PI * 10 * time );
}

void advanceInputs( Vector *inputs ) {
    int i;

    for( i = inputs->elements - 1; i > 0; --i ) {
        inputs->a[i] = inputs->a[i - 1];
    }
    inputs->a[0] = nextValue();
}

int main( int argc, char *argv[] ) {
    Vector inputs; inputs.elements = PERCEPTRON_INPUTS;
    Vector weights; weights.elements = PERCEPTRON_INPUTS;
    int i, j;

    for( i = 0; i < inputs.elements; ++i ) {
        advanceInputs( &inputs );
    }

    return 0;
}
