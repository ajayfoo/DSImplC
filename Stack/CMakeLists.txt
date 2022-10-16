cmake_minimum_required(VERSION 3.20)

project(Stack)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

set(DO_TESTS TRUE)

add_subdirectory(src)

if(DO_TESTS)
    add_subdirectory(test)
    target_link_libraries(run_io_tests PRIVATE stack)
    target_link_libraries(run_non_io_tests PRIVATE stack)
endif()

