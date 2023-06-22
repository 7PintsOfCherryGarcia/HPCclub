CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -g


all:simple_regression

simple_regression:simple_regression.c least_squares.c	kad_rand.c least_squares.h
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f simple_regression
