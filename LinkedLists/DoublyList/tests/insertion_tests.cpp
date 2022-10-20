#include "gtest/gtest.h"

extern "C"
{
#include "doubly_list.h"
}

TEST(InsertionTests, EmptyList)
{
    DoublyList doubly_list;
    init_doubly_list(&doubly_list);
    ASSERT_EQ(doubly_list.m_length, 0);
    clear_doubly_list(&doubly_list);
}