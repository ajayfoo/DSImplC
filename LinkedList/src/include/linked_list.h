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
    ListNode* m_head;
    ListNode* m_tail;
    size_t m_length;
} LinkedList;

LinkedList* get_new_linked_list(void);
void insert_at_head(LinkedList* linked_list, int data);
void insert_after_tail(LinkedList* linked_list, int data);
void insert_at(LinkedList* linked_list, size_t index, int data);
void print_linked_list(LinkedList* linked_list);
void delete_head(LinkedList* linked_list);

#endif
