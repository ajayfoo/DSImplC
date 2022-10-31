#ifndef DS_IMPL_C_CIRCULAR_LIST_H
#define DS_IMPL_C_CIRCULAR_LIST_H

#include <stddef.h>

struct ListNode
{
    int m_data;
    struct ListNode* m_next;
};

typedef struct ListNode ListNode;

typedef struct
{
    ListNode* m_tail;
    size_t m_length;
} CircularList;

void cl_init_circular_list(CircularList* circular_list);

void cl_insert_at_head(CircularList* circular_list, int data);

void cl_insert_after_tail(CircularList* circular_list, int data);

void cl_insert_at(CircularList* circular_list, size_t index, int data);

void cl_print_circular_list(CircularList* circular_list);

void cl_delete_head(CircularList* circular_list);

void cl_delete_tail(CircularList* circular_list);

void dl_delete_at(CircularList* circular_list, size_t index);

void cl_clear_circular_list(CircularList* circular_list);

#endif
