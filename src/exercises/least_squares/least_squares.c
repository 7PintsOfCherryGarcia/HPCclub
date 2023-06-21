#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    kad_srand(NULL, time(NULL));
    if ( (e < 0) || (e > 5) ) return NULL;
    float *y = malloc(size * sizeof(float));
    if (!y) return NULL;
    for (unsigned int i = 0; i < size; i++) {
        y[i] = x[i]*b0 + b1 + kad_drand_normal(NULL)*e;
    }
    return y;
}

static float mean(float *x, unsigned int size)
{
    double m = 0.0;
    for (unsigned int i = 0; i < size; i++)
        m += x[i];
    return (float)( m/size );
}

float lm_genb0(float *x, float *y, unsigned int size)
{
    double mean_x = mean(x, size);
    double mean_y = mean(y, size);
    double num = 0.0, den = 0.0;
    for (unsigned int i = 0; i < size; i++) {
        num += ( x[i]*y[i] - x[i]*mean_y );
        den += (x[i]*x[i] - x[i]*mean_x);
    }
    return (float)( num/den );
}

float lm_genb1(float *x, float *y, unsigned int size, float  b0)
{
    return mean(y, size) - b0*mean(x, size);
}
