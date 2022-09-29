cmake_minimum_required(VERSION 3.23)

project(DynamicArray C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(dynamic_array)
add_executable(exec_program exec_program.c)

target_link_libraries(exec_program dynamic_array)

if (MSVC)
    add_compile_options(/W4 /WX)
else ()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif ()