#include <stdlib.h>
#include "centroid.h"
#include <math.h>

float euc_s(float *p1, float *p2, unsigned int dim)
{
    float s = 0.0;
    for (unsigned int i = 0; i < dim; i++){
        s += (p1[i]-p2[i])*(p1[i]-p2[i]);
    }
    return sqrtf(s);
}

float *centroid(float *m, unsigned int dim, unsigned int n)
{
    float *c = calloc(dim, sizeof(float));
    if (!c) return NULL;
    for (unsigned int i = 0; i < n*dim; i+=dim) {
        for (unsigned int j = 0; j < dim; j++)
            c[j] += m[i + j];
    }
    for (unsigned int j = 0; j < dim; j++)
        c[j] /= n;
    return c;
}

float *s2center(float *m, unsigned int dim, unsigned int n)
{
    float *s_vec = malloc(n * sizeof(float));
    if (!s_vec) return NULL;
    float *center = centroid(m, dim, n);
    for (unsigned int i = 0; i < n*dim; i+=dim) {
        s_vec[i] = euc_s(m + i, center, dim);
    }
    return s_vec;
}
