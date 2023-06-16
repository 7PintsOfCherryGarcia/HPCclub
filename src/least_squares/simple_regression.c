/*
Exercise for the HPCclub

Implement the computation of a simple linear regression.

Given a two dimensional dataset of the form (X, Y).
Compute the line of best fit B0*X + B1 using ordinary least squares.

Definitions of code for parameter computation should be placed in least_squares.c
Declarations should live in least_squares.h

Compilation command:
gcc -Wall -Wextra -pedantic -o simple_regression simple_regression.c least_squares.c kad_rand.c -lm

*/

#include <stdio.h>
#include <stdlib.h>
#include "least_squares.h"

#define minX   0
#define maxX  10
#define B0   .85
#define B1     3
#define NOISE .5

#define PRINT_DATA 1


void print_data(float *x, float *y, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        fprintf(stdout, "%.2f\t%.2f\n", x[i], y[i]);
}

int main(int argc, char *argv[])
{
    if (argc < 2) goto error;
    unsigned int npoints = atoi(argv[1]);
    if (npoints == 0) goto error;

    //Generate out independent variable
    float *x = gen_independent(npoints, minX, maxX);
    if (!x) goto error;
    //From our independent variable, generate a response variable
    //given a linear model B0X + B1 + NOISE
    float *y = gen_dependent(x, npoints, B0, B1, NOISE);
    if (!y) goto error;

    if (PRINT_DATA) print_data(x, y, npoints);

    float estB0 = lm_genb0(x, y, npoints);
    float estB1 = lm_genb1(x, y, npoints, B0);

    fprintf(stderr, "Slope (B0): %.4f\n", estB0);
    fprintf(stderr, "Intercept (B1): %.4f\n", estB1);

    //Release the memory we allocated
    free(x);
    free(y);
    return 0;
    error:
        if (x) free(x);
        if (y) free(y);
        fprintf(stderr, "ERROR: Something went badly :(\n");
        return -1;
}
