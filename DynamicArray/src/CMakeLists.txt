cmake_minimum_required(VERSION 3.20)

add_library(dynamic_array include/dynamic_array.h dynamic_array.c)

target_include_directories(dynamic_array PUBLIC include)