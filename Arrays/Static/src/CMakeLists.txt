cmake_minimum_required(VERSION 3.20)

project(StaticArray C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(exec_program exec_program.c exec_program.c)

add_subdirectory(static_array)
target_link_libraries(exec_program PRIVATE static_array) 