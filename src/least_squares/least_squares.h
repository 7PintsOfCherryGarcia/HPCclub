//APIs for simple regression parameter estimation exercise

//Generate normaly distributed random numbers with mean - 0 and standard deviation - 1
double kad_drand_normal(void *d);

//Generate a npoints numbers in the range [min - max]
float *gen_independent(unsigned int npoints, int min, int max);

//Given an input vector x generate a response variable following a linear model:
//    B0x + B1 + e where e is an error parameter corresponding to the standard
//    deviation of a normal distribution
float *gen_dependent(float *x, unsigned int size, float b0, float b1, float e);

float lm_genb0(float *x, float *y, unsigned int size);

float lm_genb1(float *x, float *y, unsigned int size, float b0);
