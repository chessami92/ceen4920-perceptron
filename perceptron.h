#define INPUTS 5

typedef struct {
    float *a;
    int elements;
} vector;

float weightedSum( vector inputs, vector weights );
float getOutput( float weightedSum );
void testInput( vector inputs, vector weights, float desiredOutput );
