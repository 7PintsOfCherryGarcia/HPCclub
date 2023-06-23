CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -c -g

.PHONY:all clean

all:centroid

centroid:centroid.c
	$(CC) $(CFLAGS) -o $@.o $^
	ar rcs lib$@.a $@.o

clean:
	rm -f centroid.o libcentroid.a
