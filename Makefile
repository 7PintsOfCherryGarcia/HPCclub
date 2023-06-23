all:libraries exercises

exercises:least_squares MC_pi centroid

libraries:kad_rand

kad_rand:
	make -C src/libraries/kad_rand
	cp src/libraries/kad_rand/libkad_rand.a ./lib

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
	make clean -C src/libraries/kad_rand
	rm -f ./bin/MC_pi ./bin/simple_regression
	rm -f ./lib/libkad_rand.a
