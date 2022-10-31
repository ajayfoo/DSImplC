
add_library(circular_list STATIC
	include/circular_list.h
	circular_list.c
)

target_include_directories(circular_list PUBLIC include)
