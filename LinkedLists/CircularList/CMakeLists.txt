cmake_minimum_required(VERSION 3.20)

project(CircularList)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

set(DO_TESTS TRUE)

add_subdirectory(src)

if(DO_TESTS)
    enable_testing()
    add_subdirectory(test)
    target_link_libraries(run_io_tests PRIVATE circular_list)
    target_link_libraries(run_non_io_tests PRIVATE circular_list)
endif()
