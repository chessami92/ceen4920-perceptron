#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "perceptron.h"
#include "random.h"

#define FLOAT_EQUALS 0.01

static void weightedSum_test( void ) {
    float a[5] = {1, 2, 3, 4 , 5};
    float b[5] = {-1.5, 2, 3, 4 , -5};
    vector inputs = {a, 5};
    vector weights = {b, 5};

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
    vector inputs = {a, 2};
    vector weights = {b, 2};
    float desired, actual, error;
    int i, j;
    int converged = 0;

    for( i = 0; i < 1000; ++i ) {
        desired = randFloat() * 2 - 1;
        a[0] = randFloat() * 2 - 1; a[1] = randFloat() * 2 - 1;
        b[0] = randFloat() / 20; b[1] = randFloat() / 20;
        for( j = 0; j < 250; ++j ) {
            testInput( inputs, weights, desired );

            actual = getOutput( weightedSum( inputs, weights ) );
            error = fabs( desired - actual );
            if( error < FLOAT_EQUALS ) {
                break;
            }
        }
        if( error < FLOAT_EQUALS ) {
            converged++;
        } else {
            printf( "inputs: %f, %f, weights: %f, %f, desired: %f, actual: %f\n", a[0], a[1], b[0], b[1], desired, actual );
        }
    }
}

int main( void ) {
    initRand();

    weightedSum_test();
    getOutput_test();
    testInput_test();
    return 0;
}
