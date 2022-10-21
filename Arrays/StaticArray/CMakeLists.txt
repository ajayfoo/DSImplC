cmake_minimum_required(VERSION 3.20)

project(StaticArray)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)
set(DO_TESTS TRUE)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)

if(DO_TESTS)
    enable_testing()
    add_subdirectory(tests)
    target_link_libraries(io_tests PRIVATE static_array)
    target_link_libraries(non_io_tests PRIVATE static_array)
endif()

