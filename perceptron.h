#define INPUTS 5

typedef struct {
    float *a;
    int elements;
} vector;

float weightedSum( vector inputs, vector weights );
