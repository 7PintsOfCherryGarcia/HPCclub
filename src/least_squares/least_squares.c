#include <stdio.h>
#include <stdlib.h>

#include "least_squares.h"

float *gen_independent(unsigned int npoints, int min, int max)
{
    if (max <= min) return NULL;
    float *x = malloc(npoints * sizeof(float));
    if (!x) return NULL;

    unsigned int range = max - min;
    float step = range / (float)npoints;
    float start = min;
    for (unsigned int i = 0; i < npoints; i++) {
        x[i] = start;
        start += step;
    }
    return x;
}

float *gen_dependent(float *x, unsigned int size, float b0, float b1, float e)
{
    if ( (e < 0) || (e > 1) ) return NULL;
    float *y = malloc(size * sizeof(float));
    if (!y) return NULL;
    for (unsigned int i = 0; i < size; i++) {
        y[i] = x[i]*b0 + b1 + kad_drand_normal(NULL)*e;
    }
    return y;
}
