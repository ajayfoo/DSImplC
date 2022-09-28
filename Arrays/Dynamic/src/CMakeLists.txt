cmake_minimum_required(VERSION 3.23)

project(DynamicArray C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(dynamic_array)
add_executable(exec_program exec_program.c)

target_link_libraries(exec_program dynamic_array)