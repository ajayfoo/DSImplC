cmake_minimum_required(VERSION 3.23)
project(Stack C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(exec_program exec_program.c)
add_subdirectory(stack)

target_link_libraries(exec_program PRIVATE stack)