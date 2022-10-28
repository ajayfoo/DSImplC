//
// Created by ajay on 10/15/22.
//
#include "gtest/gtest.h"

extern "C" {
#include "static_array.h"
}

TEST(InsertionTests, EmptyArray) {
  StaticArray static_array;
  init_static_array(&static_array);
  ASSERT_EQ(static_array.m_length, 0);
}
