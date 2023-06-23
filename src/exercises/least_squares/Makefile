CC=gcc
CFLAGS= -Wall -Wextra -std=c11 -pedantic -L../../../lib  -g -O2


all:simple_regression

simple_regression:simple_regression.c least_squares.c	least_squares.h
	$(CC) $(CFLAGS) -o $@ $^ -lkad_rand -lm

clean:
	rm -f simple_regression
