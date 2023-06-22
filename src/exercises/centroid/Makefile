CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -c -g


all:centroid

centroid:centroid.c
	$(CC) $(CFLAGS) -o $@.o $^

clean:
	rm -f centroid.o
