#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define PI 3.1415926535897932

typedef struct {
    uint64_t s[2];
    double n_gset;
    int n_iset;
    volatile int lock;
} kad_rng_t;


/***************************
 * Random number generator *
 ***************************/

static kad_rng_t kad_rng_dat = {
    {0x50f5647d2380309dULL,
     0x91ffa96fc4c62cceULL},
    0.0,
    0,
    0
};

static inline uint64_t kad_splitmix64(uint64_t x)
{
	uint64_t z = (x += 0x9E3779B97F4A7C15ULL);
	z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
	z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
	return z ^ (z >> 31);
}

static inline uint64_t kad_xoroshiro128plus_next(kad_rng_t *r)
{
	const uint64_t s0 = r->s[0];
	uint64_t s1 = r->s[1];
	const uint64_t result = s0 + s1;
	s1 ^= s0;
	r->s[0] = (s0 << 55 | s0 >> 9) ^ s1 ^ (s1 << 14);
	r->s[1] = s0 << 36 | s0 >> 28;
	return result;
}

static inline void kad_xoroshiro128plus_jump(kad_rng_t *r)
{
	static const uint64_t JUMP[] = { 0xbeac0467eba5facbULL, 0xd86b048b86aa9922ULL };
	uint64_t s0 = 0, s1 = 0;
	int i, b;
	for (i = 0; i < 2; ++i)
		for (b = 0; b < 64; b++) {
			if (JUMP[i] & 1ULL << b)
				s0 ^= r->s[0], s1 ^= r->s[1];
			kad_xoroshiro128plus_next(r);
		}
	r->s[0] = s0, r->s[1] = s1;
}

void kad_srand(void *d, uint64_t seed)
{
	kad_rng_t *r = d? (kad_rng_t*)d : &kad_rng_dat;
	r->n_gset = 0.0, r->n_iset = 0;
	r->s[0] = kad_splitmix64(seed);
	r->s[1] = kad_splitmix64(r->s[0]);
}

void *kad_rng(void)
{
	kad_rng_t *r;
	r = (kad_rng_t*)calloc(1, sizeof(kad_rng_t));
	kad_xoroshiro128plus_jump(&kad_rng_dat);
	r->s[0] = kad_rng_dat.s[0], r->s[1] = kad_rng_dat.s[1];
	return r;
}

uint64_t kad_rand(void *d)
{
    return kad_xoroshiro128plus_next(d? (kad_rng_t*)d : &kad_rng_dat);
}

double kad_drand(void *d)
{
	union { uint64_t i; double d; } u;
	u.i = 0x3FFULL << 52 | kad_xoroshiro128plus_next(d? (kad_rng_t*)d : &kad_rng_dat) >> 12;
	return u.d - 1.0;
}

double kad_drand_normal(void *d)
{
	kad_rng_t *r = d? (kad_rng_t*)d : &kad_rng_dat;
	if (r->n_iset == 0) {
		double fac, rsq, v1, v2;
		do {
			v1 = 2.0 * kad_drand(d) - 1.0;
			v2 = 2.0 * kad_drand(d) - 1.0;
			rsq = v1 * v1 + v2 * v2;
		} while (rsq >= 1.0 || rsq == 0.0);
		fac = sqrt(-2.0 * log(rsq) / rsq);
		r->n_gset = v1 * fac;
		r->n_iset = 1;
		return v2 * fac;
	} else {
		r->n_iset = 0;
		return r->n_gset;
	}
}

double kad_drand_box_muller(void *d)
{
    kad_rng_t *r = d? (kad_rng_t*)d : &kad_rng_dat;
    if (r->n_iset == 0) {
        double v1, v2;
        v1 = sqrt(-2.0*log(kad_drand(d)))*cos(2.0*PI*kad_drand(d));
        v2 = sqrt(-2.0*log(kad_drand(d)))*sin(2.0*PI*kad_drand(d));
        r->n_gset = v1;
        r->n_iset = 1;
        return v2;
    } else {
        r->n_iset = 0;
        return r->n_gset;
    }
}
