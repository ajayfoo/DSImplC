cmake_minimum_required(VERSION 3.20)

add_library(stack STATIC include/stack.h stack.c)
target_include_directories(stack PUBLIC include)