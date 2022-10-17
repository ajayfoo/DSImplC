add_library(doubly_list include/doubly_list.h doubly_list.c)

target_include_directories(doubly_list PUBLIC include)

if (MSVC)
    target_compile_options(doubly_list PRIVATE /W4 /WX)
else()
    target_compile_options(doubly_list PRIVATE -Wall -Wextra -pedantic -Werror )
endif()