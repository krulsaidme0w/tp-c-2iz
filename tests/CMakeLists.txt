#find_package(GTest REQUIRED)
#find_package(Threads REQUIRED)

#add_executable(tests tests.cpp main.cpp)


#add_test(NAME tests COMMAND tests)

#target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads no_procs with_procs menu)



find_package(Threads REQUIRED)

include(ExternalProject)

#add_subdirectory(menu)
#add_subdirectory(no procs)
#add_subdirectory(with procs)