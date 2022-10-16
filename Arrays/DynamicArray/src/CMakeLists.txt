
add_library(dynamic_array include/dynamic_array.h dynamic_array.c)

target_include_directories(dynamic_array PUBLIC include)

if (MSVC)
    target_compile_options(dynamic_array PRIVATE /W4 /WX)
else()
    target_compile_options(dynamic_array PRIVATE -Wall -Wextra -pedantic -Werror )
endif()