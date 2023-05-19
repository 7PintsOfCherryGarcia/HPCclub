#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*
  Find if a point is within the boundaries of a unit circle centered at 0,0
  Parameters:
      x - x coordinate of point
      y - y coordinate of point
  Returns:
      0 if out of circle
      1 if in  of circle
*/
int MC_incircle(float x, float y)
{
    if ( sqrt(x*x + y*y) > 1.0 ) return 0;
    return 1;
}

/*
  Estimate the value of pi by sampling from the uniform
  Parameters:
      size - Number of points to sample
  Returns:
      Pi estimate

 */
double MC_compute(int size)
{
    float x, y;
    float c = 0;
    for (int i = 0; i < size; i++) {
        x = random() / (float)RAND_MAX;
        y = random() / (float)RAND_MAX;
        if (MC_incircle(x,y)) c++;
    }
    return 4 * c / (float)size;
}

/*
  Run a Montecarlo based estimation of pi
  Parameters:
      nrep - Number of estimates to compute
      size - Number of points to sample per estimate
 */
float MC_run(int nrep, int size)
{
    double pi = 0.0;
    for (int i = 0; i < nrep; i++) {
        pi += MC_compute(size);
    }
    return pi / (float)nrep;
}

int main(int argc, char *argv[])
{
    srandom(time(NULL)); //Random value seed initialization
    if (argc < 3) return -1;
    int nrep = atoi(argv[1]);
    int size = atoi(argv[2]);
    float pi_est = MC_run(nrep, size);
    fprintf(stderr, "PI estimation: %f\n", pi_est);
    return 0;
}
