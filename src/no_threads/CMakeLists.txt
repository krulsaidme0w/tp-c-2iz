add_library(no_threads no_threads.h no_threads.c)

target_include_directories(no_threads PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})