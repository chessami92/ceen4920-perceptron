#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "perceptron.h"
#include "random.h"

#define FLOAT_EQUALS 0.01

static void weightedSum_test( void ) {
    float a[5] = {1, 2, 3, 4 , 5};
    float b[5] = {-1.5, 2, 3, 4 , -5};
    Vector inputs = {a, 5};
    Vector weights = {b, 5};

    assert( weightedSum( inputs, weights ) == 2.5 && "Weighted sums not being calculated correctly" );
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

static void testInput_test( void ) {
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
            testInput( testCase, weights );

            actual = getOutput( weightedSum( inputs, weights ) );
            error = fabs( testCase.desiredOutput - actual );
            if( error < FLOAT_EQUALS ) {
                converged++;
                break;
            }
        }
    }

    assert( converged > 900 && "Should have had a better convergence rate" );
}

static void testInput_OR( void ) {

}

int main( void ) {
    initRand();

    weightedSum_test();
    getOutput_test();
    testInput_test();
    return 0;
}
