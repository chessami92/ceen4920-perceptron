#include <stdio.h>
#include <string.h>
#include <math.h>
#include "perceptron.h"
#include "random.h"

#define PERCEPTRON_INPUTS 5

float nextValue( void ) {
    static float time = 0;
    time += 0.01;
    return 0.5 * sin( 2 * M_PI * 10 * time );
}

void advanceInputs( Vector *inputs, float nextValue ) {
    int i;

    for( i = inputs->elements - 1; i > 0; --i ) {
        inputs->a[i] = inputs->a[i - 1];
    }
    inputs->a[0] = nextValue;
}

int main( int argc, char *argv[] ) {
    initRand();

    float inputsA[PERCEPTRON_INPUTS];
    float weightsA[PERCEPTRON_INPUTS];
    Vector inputs;
    Vector weights;
    TestCase testCase = {&inputs, 0.0};
    float output, error;
    int i;

    inputs.a = inputsA; inputs.elements = PERCEPTRON_INPUTS;
    weights.a = weightsA; weights.elements = PERCEPTRON_INPUTS;

    for( i = 0; i < weights.elements; ++i ) {
        weights.a[i] = randFloat() / 20;
    }

    for( i = 0; i < inputs.elements; ++i ) {
        advanceInputs( &inputs, nextValue() );
    }

    for( i = 0; i < 10000; ++i ) {
        testCase.desiredOutput = nextValue();
        updateWeights( &testCase, &weights );
        advanceInputs( &inputs, testCase.desiredOutput );
    }

    float nextVal;
    for( i = 0; i < 250; ++ i ) {
        nextVal = nextValue();
        output = getOutput( weightedSum( &inputs, &weights ) );
        error = fabs( output - nextVal );
        printf( "%f,%f\n", nextVal, output );
        advanceInputs( &inputs, output );
    }

    for( i = 0; i < weights.elements; ++i ) {
        printf( "%f\n", weights.a[i] );
    }

    return 0;
}
