#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "circular_list.h"
#include <stddef.h>

struct ListNode
{
    int m_data;
    struct ListNode* m_next;
};

struct ListBlock
{
    CircularList* m_block;
};

typedef struct ListNode ListNode;

typedef struct
{
    ListNode* m_head;
    ListNode* m_tail;
    size_t m_length;
} UnrolledList;

void init_unrolled_list(UnrolledList* unrolled_list);
void insert_at_head(UnrolledList* unrolled_list, int data);
void insert_after_tail(UnrolledList* unrolled_list, int data);
void insert_at(UnrolledList* unrolled_list, size_t index, int data);
void print_unrolled_list(UnrolledList* unrolled_list);
void delete_head(UnrolledList* unrolled_list);
void delete_tail(UnrolledList* unrolled_list);
void delete_at(UnrolledList* unrolled_list, size_t index);
void clear_unrolled_list(UnrolledList* unrolled_list);

#endif
