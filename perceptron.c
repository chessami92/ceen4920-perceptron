#include <stdio.h>
#include "perceptron.h"

float weightedSum( vector inputs, vector weights ) {
    float returnVal = 0;
    int i;

    if( inputs.elements != weights.elements ) {
        return 0;
    }

    for( i = 0; i < inputs.elements; ++i ) {
        returnVal += inputs.a[i] * weights.a[i];
    }

    return returnVal;
}
