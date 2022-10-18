add_library(circular_list include/circular_list.h circular_list.c)

target_include_directories(circular_list PUBLIC include)

if (MSVC)
    target_compile_options(circular_list PRIVATE /W4 /WX)
else()
    target_compile_options(circular_list PRIVATE -Wall -Wextra -pedantic -Werror )
endif()