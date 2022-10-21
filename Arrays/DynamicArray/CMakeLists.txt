cmake_minimum_required(VERSION 3.20)

project(DynamicArray)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

set(DO_TESTS TRUE)

add_subdirectory(src)

if(DO_TESTS)
    add_subdirectory(test)
    target_link_libraries(io_tests PRIVATE dynamic_array)
    target_link_libraries(non_io_tests PRIVATE dynamic_array)
endif()

