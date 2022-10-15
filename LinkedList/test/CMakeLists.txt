include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(gtest)

add_executable(all_tests insertion_tests.cpp)

target_link_libraries(
        all_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(all_tests)
