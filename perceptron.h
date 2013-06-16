#define INPUTS 5

typedef struct {
    float *a;
    int elements;
} Vector;

typedef struct {
    Vector inputs;
    float desiredOutput;
} TestCase;

float weightedSum( Vector inputs, Vector weights );
float getOutput( float weightedSum );
void updateWeights( TestCase testCase, Vector weights );
