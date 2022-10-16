
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS OFF)

add_library(static_array STATIC include/static_array.h static_array.c)
target_include_directories(static_array PUBLIC include)