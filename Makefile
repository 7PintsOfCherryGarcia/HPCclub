all:least_squares

least_squares:
	make -C src/exercises/least_squares
	cp src/exercises/least_squares/simple_regression ./bin
