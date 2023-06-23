CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -g -L../../../lib -I../../../include
LIBS=-lkad_rand -lcentroid -lm

all:centroid

centroid:centroid.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f centroid
