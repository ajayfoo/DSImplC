//
// Created by ajay on 10/17/22.
//
#include "gtest/gtest.h"
#include<exception>

extern "C"
{
#include "doubly_list.h"
}

TEST(DeletionTests, DeleteHead)
{
    DoublyList* doubly_list = get_dummy_doubly_list();
    delete_head(doubly_list);
    ASSERT_EQ(doubly_list->m_head->m_data, 2);
    clear_doubly_list(doubly_list);
}
