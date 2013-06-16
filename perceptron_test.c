#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "perceptron.h"
#include "random.h"

#define FLOAT_EQUALS 0.01
#define true 1;
#define false 0;

typedef int boolean;

static void weightedSum_test( void ) {
    float a[5] = {1, 2, 3, 4 , 5};
    float b[5] = {-1.5, 2, 3, 4 , -5};
    Vector inputs = {a, 5};
    Vector weights = {b, 5};

    assert( weightedSum( &inputs, &weights ) == 2.5 && "Weighted sums not being calculated correctly" );
}

static void getOutput_test( void ) {
    float output;
    int i;

    for( i = -50; i < 50; ++i ) {
        output = getOutput( ( float )i );
        assert( output >= -1 && "Output can't be less than -1" );
        assert( output <= 1 && "Output can't be greater than 1" );
    }
}

static void updateWeights_test( void ) {
    float a[2];
    float b[2];
    float actual, error;
    Vector inputs = {a, 2};
    Vector weights = {b, 2};
    TestCase testCase = {inputs, 0.0};
    int i, j;
    int converged = 0;

    for( i = 0; i < 1000; ++i ) {
        testCase.desiredOutput = randFloat() * 2 - 1;
        a[0] = randFloat() * 2 - 1; a[1] = randFloat() * 2 - 1;
        b[0] = randFloat() / 20; b[1] = randFloat() / 20;
        for( j = 0; j < 250; ++j ) {
            updateWeights( &testCase, &weights );

            actual = getOutput( weightedSum( &inputs, &weights ) );
            error = fabs( testCase.desiredOutput - actual );
            if( error < FLOAT_EQUALS ) {
                converged++;
                break;
            }
        }
    }

    assert( converged > 900 && "Should have had a better convergence rate" );
}

static makeTestCases( float a[][3], Vector inputs[], TestCase testCases[] ) {
    int i;

    for( i = 0; i < 8; ++i ) {
        inputs[i].a = a[i];
        inputs[i].elements = 3;
        testCases[i].inputs = inputs[i];
    }

    testCases[0].desiredOutput = -1; testCases[1].desiredOutput = -1;
    testCases[2].desiredOutput = -1; testCases[3].desiredOutput = 1;
    testCases[4].desiredOutput = -1; testCases[5].desiredOutput = 1;
    testCases[6].desiredOutput = 1; testCases[7].desiredOutput = 1;
}

static boolean isTrained( TestCase testCases[], Vector weights ) {
    int i;
    float output, error;

    for( i = 0; i < 8; ++i ) {
        output = getOutput( weightedSum( &testCases[i].inputs, &weights ) );
        error = fabs( output - testCases[i].desiredOutput );
        if( error > FLOAT_EQUALS ) {
            return false;
        }
    }

    return true;
}

static void majorityFunction( void ) {
    float a[8][3] = {{-1, -1 , -1}, {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},
        {1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {1, 1, 1}};
    float b[3] = {randFloat() / 20, randFloat() / 20, randFloat() / 20};
    Vector inputs[8];
    Vector weights = {b, 3};
    TestCase testCases[8];
    int i, j, maxIterations = 10000;

    makeTestCases( a, inputs, testCases );

    for( i = 0; i < maxIterations; ++i) {
        updateWeights( &testCases[i % 8], &weights );
        if( isTrained( testCases, weights ) ) {
            break;
        }
    }

    assert( i != maxIterations && "Should have finished training before 10000 iterations.");

    printf( "Took %d iterations\n", i );
    printf( "Weights: %f %f %f\n", b[0], b[1], b[2] );
    for( i = 0; i < 8; ++i ) {
        printf( "Inputs: % 5.2f % 5.2f % 5.2f, Output: %f\n", a[i][0], a[i][1], a[i][2],
            getOutput( weightedSum( &testCases[i].inputs, &weights) ) );
    }
}

int main( void ) {
    initRand();

    weightedSum_test();
    getOutput_test();
    updateWeights_test();
    majorityFunction();
    return 0;
}
