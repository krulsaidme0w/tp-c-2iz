build-pr:
	rm -rf build/ && mkdir build && cd build && cmake .. && make

run-pr:
	cd build/cmd/ && ./main

build-n-run:
	make build && make run


run-menu-test:
	cd build/tests/menu && ./menu_test

run-no-procs:
	cd build/tests/no_procs/ && ./noprocs_test

run-with-procs:
	cd build/tests/with_procs/ && ./withprocs_test

run-all-tests:
	make run-menu-test && make run-no-procs && make run-with-procs

gen-words:
	cd src/word_gen/ && python3 word_gen.py 50000 150 300

valgrind-menu:
	cd build/tests/menu/ && valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./menu_test

valgrind-no-procs:
	cd build/tests/no_procs/ && valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./noprocs_test

valgrind-with-procs:
	cd build/tests/with_procs/ && valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./withprocs_test

valgrind:
	make valgrind-menu && make valgrind-no-procs && valgrind-with-procs

#coverage:
	#cd build/src//CMakeFiles/storage.dir && gcov *.gcno && lcov --capture --directory . --output-file coverage.info && mkdir coverage && genhtml coverage.info --output-directory coverage