add_library(menu menu.h menu.c)

target_include_directories(menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(menu LINK_PUBLIC no_procs with_procs)