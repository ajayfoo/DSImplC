add_library(xor_list include/xor_list.h xor_list.c)

target_include_directories(xor_list PUBLIC include)

if (MSVC)
    target_compile_options(xor_list PRIVATE /W4 /WX)
else()
    target_compile_options(xor_list PRIVATE -Wall -Wextra -pedantic -Werror )
endif()