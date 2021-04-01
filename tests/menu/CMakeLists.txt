project(menu_test)

add_executable(${PROJECT_NAME}  tests.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} Threads::Threads menu no_procs with_procs)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})