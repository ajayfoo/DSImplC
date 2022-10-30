#include "gtest/gtest.h"

extern "C"
{
#include "xor_list.h"
}

TEST(InsertionTest, InsertOneElement)
{
    XORList xor_list;
    init_xor_list(&xor_list);
    insert_at_head(&xor_list, 4);
    ASSERT_EQ(1, xor_list.m_length);
    clear_xor_list(&xor_list);
}
