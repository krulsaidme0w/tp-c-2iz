cmake_minimum_required(VERSION 3.17)
project(tp_c_iz2 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic  -lpthread -fprofile-arcs -ftest-coverage")

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(cmd)

configure_file(src/word_gen/words.txt cmd/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/menu/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/no_procs/words.txt COPYONLY)
configure_file(src/word_gen/words.txt tests/with_procs/words.txt COPYONLY)