/* Creates two clouds of 2 dimensional points with mean center X1, Y1 and X2, Y2.
 * Optionally, the dataset is printed to stdout
 *
 * Objectives:
 *   What is the average distance of each cloud of points to it's centroid?
 *   What is the average distance of each cloud of points to the centroid of the
 *      other cloud of points?
 *   What is the centroid of the entire dataset?
 *   What is the average distance of each point to the centroid of the entire dataset?
 *   What is the distance between the centroids of each cloud?
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "libcentroid.h"
#include "libkad_rand.h"

#define X1  1.1f
#define Y1  4.6f
#define X2 -2.3f
#define Y2  5.6f
#define SDEV 1.0f
#define PRINT_DATA 1

void print_data(float *data1, float *data2, unsigned int n)
{
    for (unsigned int i = 0; i < 2*n; i+= 2) {
        fprintf(stdout, "%.4f\t%.4f\t%.4f\t%.4f\n", data1[i], data1[i+1],
                                                    data2[i], data2[i+1]);
    }
}

float *gen_data(float mean1, float mean2, float sdev, unsigned int n)
{
    float *data = malloc(2 * n * sizeof(float));
    if (!data) return NULL;

    for (unsigned int i = 0; i < 2*n; i+=2) {
        data[i] = kad_drand_normal(NULL)*sdev + mean1;
        data[i + 1] = kad_drand_normal(NULL)*sdev + mean2;
    }
    return data;
}

int main(int argc, char *argv[])
{
    int ret = 1;
    if (argc < 2) return ret;
    unsigned int npoints = atoi(argv[1]);
    if ( 0 == npoints) return ret;
    kad_srand(NULL, time(NULL));

    float *data1 = gen_data(X1, Y1, SDEV, npoints);
    float *data2 = gen_data(X2, Y2, SDEV, npoints);
    if ( !data1 || !data2 ) goto exit;
    if (PRINT_DATA) print_data(data1, data2, npoints);

    ret = 0;
    exit:
        if (data1) free(data1);
        if (data2) free(data2);
        return ret;
}
