project(stress_test)

add_executable(${PROJECT_NAME}  stress_tests.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} Threads::Threads with_procs no_procs menu)