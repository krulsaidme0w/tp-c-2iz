find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(tests tests.cpp main.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads no_procs with_procs menu)