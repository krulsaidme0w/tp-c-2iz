add_executable(main main.c)

target_link_libraries(main LINK_PUBLIC no_threads with_threads)