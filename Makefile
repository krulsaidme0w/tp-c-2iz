build:
	rm -rf build/ && mkdir build && cd build && cmake .. && make

run:
	cd build/cmd/ && ./main

build-n-run:
	make build && make run

run-all-tests:
	cd build/tests/ && ./tests