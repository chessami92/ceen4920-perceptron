typedef struct {
#ifdef PERCEPTRON_INPUTS
    float a[PERCEPTRON_INPUTS];
#else
    float *a;
#endif
    int elements;
} Vector;

typedef struct {
    Vector inputs;
    float desiredOutput;
} TestCase;

float weightedSum( Vector inputs, Vector weights );
float getOutput( float weightedSum );
void updateWeights( TestCase testCase, Vector weights );
