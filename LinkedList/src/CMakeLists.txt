add_library(linked_list include/linked_list.h linked_list.c)

target_include_directories(linked_list PUBLIC include)

if (MSVC)
    target_compile_options(linked_list PRIVATE /W4 /WX)
else()
    target_compile_options(linked_list PRIVATE -Wall -Wextra -pedantic -Werror )
endif()