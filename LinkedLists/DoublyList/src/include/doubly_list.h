#ifndef doubly_list_H
#define doubly_list_H

#include <stddef.h>

struct ListNode
{
    int m_data;
    struct ListNode* m_next;
    struct ListNode* m_prev;
};

typedef struct ListNode ListNode;

typedef struct
{
    ListNode* m_head;
    ListNode* m_tail;
    size_t m_length;
} DoublyList;

DoublyList* get_new_doubly_list(void);

void insert_at_head(DoublyList* doubly_list, int data);

void insert_after_tail(DoublyList* doubly_list, int data);

void insert_at(DoublyList* doubly_list, size_t index, int data);

void print_doubly_list(DoublyList* doubly_list);

void delete_head(DoublyList* doubly_list);

void delete_tail(DoublyList* doubly_list);

void delete_at(DoublyList* doubly_list, size_t index);

void clear_doubly_list(DoublyList* doubly_list);

DoublyList* get_dummy_doubly_list(void);

#endif
