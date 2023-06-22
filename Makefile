all:least_squares MC_pi centroid

least_squares:
	make -C src/exercises/least_squares
	cp src/exercises/least_squares/simple_regression ./bin

MC_pi:
	make -C src/exercises/MC_pi
	cp src/exercises/MC_pi/MC_pi ./bin

centroid:
	make -C src/exercises/centroid

clean:
	make clean -C src/exercises/MC_pi
	make clean -C src/exercises/least_squares
	make clean -C src/exercises/centroid
	rm -f ./bin/MC_pi ./bin/least_squares
