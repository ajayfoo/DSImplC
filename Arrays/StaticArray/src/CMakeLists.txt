add_library(static_array STATIC include/static_array.h static_array.c)
target_include_directories(static_array PUBLIC include)