all:libraries exercises

libraries:folders libkad_rand libcentroid
exercises:least_squares MC_pi centroid


libkad_rand:folders
	make -C src/libraries/libkad_rand
	cp src/libraries/libkad_rand/libkad_rand.a ./lib
	cp src/libraries/libkad_rand/libkad_rand.h ./include

libcentroid:folders
	make -C src/libraries/libcentroid
	cp src/libraries/libcentroid/libcentroid.a ./lib
	cp src/libraries/libcentroid/libcentroid.h ./include

folders:
	mkdir -p bin lib include


least_squares:
	make -C src/exercises/least_squares
	cp src/exercises/least_squares/simple_regression ./bin

MC_pi:
	make -C src/exercises/MC_pi
	cp src/exercises/MC_pi/MC_pi ./bin

centroid:
	make -C src/exercises/centroid
	cp src/exercises/centroid/centroid ./bin


clean:
	make clean -C src/exercises/MC_pi
	make clean -C src/exercises/least_squares
	make clean -C src/libraries/libcentroid
	make clean -C src/libraries/libkad_rand
	rm -f ./bin/MC_pi ./bin/simple_regression
	rm -f ./lib/libkad_rand.a ./lib/libcentroid.a
	rm -f ./include/libkad_rand.h ./include/libcentroid.h
