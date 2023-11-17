.PHONY: build run test octagontest triangletest hexagontest pointtest

build: clean-build
	mkdir build
	git submodule init
	git submodule update
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test:
	./build/*_test

octagontest:
	./build/octagon_test

triangletest:
	./build/triangle_test

hexagontest:
	./build/hexagon_test

pointtest:
	./build/point_test

clean-build:
	rm -rf ./build/
