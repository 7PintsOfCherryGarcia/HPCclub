CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -c -O2

.PHONY:all clean

all:kad_rand

kad_rand:kad_rand.c
	$(CC) $(CFLAGS) -o $@.o $^
	ar rcs lib$@.a $@.o

clean:
	rm -f kad_rand.o libkad_rand.a
