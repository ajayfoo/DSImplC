cmake_minimum_required(VERSION 3.20)

project(LinkedList C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS TRUE)
set(DO_TESTS TRUE)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)

if(DO_TESTS)
    enable_testing()
    add_subdirectory(test) 
    target_link_libraries(run_io_tests PRIVATE linked_list)
endif()
