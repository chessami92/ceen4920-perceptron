#define INPUTS 5

typedef struct {
    float *a;
    int elements;
} Vector;

float weightedSum( Vector inputs, Vector weights );
float getOutput( float weightedSum );
void testInput( Vector inputs, Vector weights, float desiredOutput );
