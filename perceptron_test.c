#include <stdio.h>
#include <assert.h>
#include "perceptron.h"

static void weightedSum_test() {
    float a[5] = {1, 2, 3, 4 , 5};
    float b[5] = {-1.5, 2, 3, 4 , -5};
    vector inputs = {a, 5};
    vector weights = {b, 5};

    assert( weightedSum( inputs, weights ) == 2.5 && "Weighted sums not being calculated correctly" );
}

int main( void ) {
    weightedSum_test();
}
