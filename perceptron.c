#include <stdio.h>
#include <math.h>
#include "perceptron.h"

float weightedSum( Vector *inputs, Vector *weights ) {
    float returnVal = 0;
    int i;

    for( i = 0; i < inputs->elements; ++i ) {
        returnVal += inputs->a[i] * weights->a[i];
    }

    return returnVal;
}

float getOutput( float weightedSum ) {
    return 2.0 / ( 1.0 + exp( -weightedSum ) ) - 1.0;
}

void updateWeights( TestCase *testCase, Vector *weights ) {
    float learningRate = 5;
    float in;
    float actualOutput;
    float error;
    float derivative;
    int i;

    in = weightedSum( testCase->inputs, weights );
    actualOutput = getOutput( in );
    error = testCase->desiredOutput - actualOutput;
    derivative = 1 / ( 2 * powf( cosh( in / 2 ), 2 ) );
    
    for( i = 0; i < weights->elements; ++i ) {
        weights->a[i] = weights->a[i] + learningRate * error * derivative * testCase->inputs->a[i];
    }
}
