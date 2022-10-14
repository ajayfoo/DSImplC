add_executable(run_all_tests main.c)
add_library(all_tests
    include/io_tests.h
    include/sloppy_tests.h
    io_tests.c
    sloppy_tests.c
)

target_include_directories(all_tests PUBLIC include)

target_link_libraries(run_all_tests PRIVATE all_tests)