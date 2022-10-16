#include "gtest/gtest.h"

extern "C"
{
#include "linked_list.h"
}

TEST(InsertionTest, InsertOneElement)
{
    LinkedList* linked_list=get_new_linked_list();
    insert_at_head(linked_list,5);
    ASSERT_EQ(1,linked_list->m_length);
    clear_linked_list(linked_list);
}
