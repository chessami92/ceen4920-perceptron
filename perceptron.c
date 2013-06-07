#include <stdio.h>
#include <math.h>
#include "perceptron.h"

float weightedSum( vector inputs, vector weights ) {
    float returnVal = 0;
    int i;

    for( i = 0; i < inputs.elements; ++i ) {
        returnVal += inputs.a[i] * weights.a[i];
    }

    return returnVal;
}

float getOutput( float weightedSum ) {
    return 2.0 / ( 1.0 + exp( -weightedSum ) ) - 1.0;
}

void testInput( vector inputs, vector weights, float desiredOutput ) {
    float learningRate = 5;
    float in;
    float actualOutput;
    float error;
    float derrivative;
    int i;

    in = weightedSum( inputs, weights );
    actualOutput = getOutput( in );
    error = desiredOutput - actualOutput;
    derrivative = 1 / ( 2 * powf( cosh( in / 2 ), 2 ) );
    
    for( i = 0; i < inputs.elements; ++i ) {
        weights.a[i] = weights.a[i] + learningRate * error * derrivative * inputs.a[i];
    }
}
