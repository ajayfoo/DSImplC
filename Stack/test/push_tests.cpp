//
// Created by ajay on 10/15/22.
//
#include "gtest/gtest.h"

extern "C"
{
#include "stack.h"
}

TEST(PushTests,EmptyStack)
{
    Stack* new_stack= init_stack(1);
    ASSERT_EQ(new_stack->m_top,-1);
    push(new_stack,3);
    ASSERT_EQ(new_stack->m_top,0);
}
