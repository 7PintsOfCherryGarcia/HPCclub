CC=gcc
CFLAGS=  -Wall -Wextra -std=c11 -pedantic -g


all:MC_pi

MC_pi:MC_pi.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f MC_pi
