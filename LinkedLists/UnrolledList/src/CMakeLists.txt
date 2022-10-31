add_subdirectory(circular_list)
add_library(unrolled_list STATIC 
	include/unrolled_list.h 
	unrolled_list.c
)

target_include_directories(unrolled_list PUBLIC include)
target_link_libraries(unrolled_list PUBLIC circular_list)
