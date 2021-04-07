find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include(ExternalProject)

add_subdirectory(menu)
add_subdirectory(no_procs)
add_subdirectory(with_procs)
add_subdirectory(stress_tests)