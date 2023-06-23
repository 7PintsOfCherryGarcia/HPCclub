#include <stdint.h>

void kad_srand(void *d, uint64_t seed);

void *kad_rng(void);

uint64_t kad_rand(void *d);

double kad_drand(void *d);

double kad_drand_normal(void *d);

double kad_drand_box_muller(void *d);
