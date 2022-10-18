#include "gtest/gtest.h"

extern "C"
{
#include "circular_list.h"
}

TEST(InsertionTest, InsertOneElement)
{
    CircularList* circular_list = get_new_circular_list();
    ASSERT_EQ(circular_list->m_length, 0);
    insert_at_head(circular_list, 8);
    ASSERT_EQ(circular_list->m_length, 1);
}
