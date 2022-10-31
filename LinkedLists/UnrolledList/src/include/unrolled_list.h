#ifndef DS_IMPL_C_UNROLLED_LIST_H
#define DS_IMPL_C_UNROLLED_LIST_H

#include "circular_list.h"
#include <stddef.h>

struct ListBlock
{
    CircularList* m_data;
    ListNode* m_next;
};

typedef struct
{
    ListNode* m_block;
    size_t m_length;
} UnrolledList;

void ul_init_unrolled_list(UnrolledList* unrolled_list);
void ul_insert_at_head(UnrolledList* unrolled_list, int data);
void ul_insert_after_tail(UnrolledList* unrolled_list, int data);
void ul_insert_at(UnrolledList* unrolled_list, size_t index, int data);
void ul_print_unrolled_list(UnrolledList* unrolled_list);
void ul_delete_head(UnrolledList* unrolled_list);
void ul_delete_tail(UnrolledList* unrolled_list);
void ul_delete_at(UnrolledList* unrolled_list, size_t index);
void ul_clear_unrolled_list(UnrolledList* unrolled_list);

#endif
