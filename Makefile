.PHONY: build run test_factory test_knight test_squirrel test_merchant clean-build

build: clean-build
	mkdir build
	cd build && cmake .. && make

run:
	./build/${PROJECT_NAME}

test_factory:
	./build/test_factory

test_knight:
	./build/test_knight

test_squirrel:
	./build/test_squirrel

test_merchant:
	./build/test_merchant

clean-build:
	rm -rf ./build/
