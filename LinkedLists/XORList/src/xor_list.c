#include "xor_list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode *get_new_list_node(int data)
{
    ListNode *new_list_node = (ListNode *)malloc(sizeof(ListNode));
    new_list_node->m_data = data;
    new_list_node->m_next = NULL;
    return new_list_node;
}

void init_xor_list(XORList *xor_list)
{
    xor_list->m_head = NULL;
    xor_list->m_tail = NULL;
    xor_list->m_length = 0;
}

void insert_after(ListNode *list_node, int data)
{
    ListNode *new_list_node = get_new_list_node(data);
    new_list_node->m_next = list_node->m_next;
    list_node->m_next = new_list_node;
}

void insert_at_head(XORList *xor_list, int data)
{
    ListNode *new_list_node = get_new_list_node(data);
    new_list_node->m_next = xor_list->m_head;
    xor_list->m_head = new_list_node;
    if (xor_list->m_tail == NULL)
    {
        xor_list->m_tail = new_list_node;
    }
    ++xor_list->m_length;
}

void insert_after_tail(XORList *xor_list, int data)
{
    if (xor_list->m_tail == NULL)
    {
        insert_at_head(xor_list, data);
    }
    else
    {
        insert_after(xor_list->m_tail, data);
        xor_list->m_tail = xor_list->m_tail->m_next;
        ++xor_list->m_length;
    }
}

void insert_at(XORList *xor_list, size_t index, int data)
{
    if (index > xor_list->m_length)
    {
        printf("It's not possible to insert at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, xor_list->m_length);
        abort();
    }
    if (index == 0)
    {
        insert_at_head(xor_list, data);
    }
    else if (index == xor_list->m_length)
    {
        insert_after_tail(xor_list, data);
    }
    else
    {
        ListNode *current_list_node = xor_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        insert_after(current_list_node, data);
        ++xor_list->m_length;
    }
}

void print_xor_list(XORList *xor_list)
{
    ListNode *current_list_node = xor_list->m_head;
    while (current_list_node != NULL)
    {
        printf("%d ", current_list_node->m_data);
        current_list_node = current_list_node->m_next;
    }
    printf("\n");
}

ListNode *delete_and_return_next_list_node(ListNode *deletion_list_node)
{
    ListNode *next_list_node = deletion_list_node->m_next;
    free(deletion_list_node);
    return next_list_node;
}

void clear_xor_list(XORList *xor_list)
{
    ListNode *current_list_node = xor_list->m_head;
    while (current_list_node != NULL)
    {
        current_list_node = delete_and_return_next_list_node(current_list_node);
    }
    xor_list->m_head = NULL;
    xor_list->m_tail = NULL;
    xor_list->m_length = 0;
}

void delete_head(XORList *xor_list)
{
    if (xor_list->m_head != NULL)
    {
        xor_list->m_head = delete_and_return_next_list_node(xor_list->m_head);
        --xor_list->m_length;
    }
    else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_tail(XORList *xor_list)
{
    if (xor_list->m_tail != NULL)
    {
        if (xor_list->m_tail == xor_list->m_head)
        {
            clear_xor_list(xor_list);
        }
        else
        {
            ListNode *current_list_node = xor_list->m_head;
            while (current_list_node->m_next != xor_list->m_tail)
            {
                current_list_node = current_list_node->m_next;
            }
            current_list_node->m_next = NULL;
            free(xor_list->m_tail);
            xor_list->m_tail = current_list_node;
            --xor_list->m_length;
        }
    }
    else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_at(XORList *xor_list, size_t index)
{
    if (index >= xor_list->m_length)
    {
        printf("It's not possible to delete the element at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, xor_list->m_length);
        abort();
    }
    else if (index == 0)
    {
        delete_head(xor_list);
    }
    else if (index == (xor_list->m_length - 1))
    {
        delete_tail(xor_list);
    }
    else
    {
        ListNode *current_list_node = xor_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        ListNode *deletion_list_node = current_list_node->m_next;
        current_list_node->m_next = current_list_node->m_next->m_next;
        free(deletion_list_node);
        --xor_list->m_length;
    }
}
