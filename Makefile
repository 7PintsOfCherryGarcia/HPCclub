

all:least_squares

least_squares:
	make -C src/least_squares
	cp src/least_squares/simple_regression ./bin
