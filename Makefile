all:least_squares MC_pi

least_squares:
	make -C src/exercises/least_squares
	cp src/exercises/least_squares/simple_regression ./bin

MC_pi:
	make -C src/exercises/MC_pi
	cp src/exercises/MC_pi/MC_pi ./bin
