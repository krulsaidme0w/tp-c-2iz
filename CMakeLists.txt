cmake_minimum_required(VERSION 3.17)
project(tp_c_iz2 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")

set(CMAKE_C_FLAGS "--coverage")

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(cmd)

configure_file(src/word_gen/words.txt cmd/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/menu/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/no_procs/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/with_procs/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/stress_tests/words.txt COPYONLY)