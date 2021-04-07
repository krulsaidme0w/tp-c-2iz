add_library(with_procs with_procs.h with_procs.c)

target_include_directories(with_procs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(with_procs LINK_PUBLIC no_procs)