cmake_minimum_required(VERSION 3.17)
project(tp_c_iz2 C CXX)

set(CMAKE_C_STANDARD 99)

set (CMAKE_C_FLAGS "-pthread -Wall -Werror -Wpedantic")

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(cmd)

configure_file(src/word_gen/words.txt cmd/words.txt COPYONLY)