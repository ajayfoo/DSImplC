
add_subdirectory(linked_list)

add_executable(run_program run_program.c)

target_link_libraries(run_program PRIVATE linked_list)