cmake_minimum_required(VERSION 3.20)

project(UnrolledList)

add_subdirectory(src)

#uncomment to disable tests
#set(DO_TESTS FALSE)

if(DO_TESTS)
    enable_testing()
    add_subdirectory(tests)
    target_link_libraries(io_tests PRIVATE unrolled_list)
    target_link_libraries(non_io_tests PRIVATE unrolled_list)
endif()

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build/compile_commands.json) 
        file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/build/compile_commands.json SYMBOLIC)
    endif()
endif()
