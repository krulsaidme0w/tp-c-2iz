add_library(with_threads with_threads.h with_threads.c)

target_include_directories(with_threads PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})