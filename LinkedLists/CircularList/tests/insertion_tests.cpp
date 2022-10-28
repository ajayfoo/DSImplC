#include "gtest/gtest.h"

extern "C"
{
#include "circular_list.h"
}

TEST(InsertionTest, InsertOneElement)
{
    CircularList circular_list;
    init_circular_list(&circular_list);
    ASSERT_EQ(circular_list.m_length, 0);
    insert_at_head(&circular_list, 8);
    ASSERT_EQ(circular_list.m_length, 1);
    clear_circular_list(&circular_list);
}
