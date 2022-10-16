//
// Created by ajay on 10/15/22.
//
#include "gtest/gtest.h"

extern "C"
{
#include "dynamic_array.h"
}

TEST(InsertionTests,EmptyArray)
{
    DynamicArray* dynamic_array=nullptr;
    dynamic_array= init_dynamic_array(dynamic_array);
    ASSERT_EQ(dynamic_array->m_length,0);
}
