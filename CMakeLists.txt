cmake_minimum_required(VERSION 3.17)
project(tp_c_iz2 C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(tp_c_iz2 cmd/main.c)