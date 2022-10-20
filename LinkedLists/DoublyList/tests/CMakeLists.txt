include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(gtest)

add_executable(run_io_tests io_tests.c)
add_executable(run_non_io_tests
        insertion_tests.cpp
        )

target_link_libraries(
        run_non_io_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_non_io_tests)

if (MSVC)
    target_compile_options(run_io_tests PRIVATE /W4 /WX)
else ()
    target_compile_options(run_io_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()