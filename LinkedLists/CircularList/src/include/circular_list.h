#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

CircularList* get_new_circular_list(void);

void insert_at_head(CircularList* circular_list, int data);

void insert_after_tail(CircularList* circular_list, int data);

void insert_at(CircularList* circular_list, size_t index, int data);

void print_circular_list(CircularList* circular_list);

void delete_head(CircularList* circular_list);

void delete_tail(CircularList* circular_list);

void delete_at(CircularList* circular_list, size_t index);

void clear_circular_list(CircularList* circular_list);

#endif
