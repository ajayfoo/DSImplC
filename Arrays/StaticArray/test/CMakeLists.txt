cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(gtest)

enable_testing()

add_executable(run_io_tests io_tests.c)
add_executable(
        run_all_tests
        insertion_tests.cpp
)
target_link_libraries(
        run_all_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_all_tests)
