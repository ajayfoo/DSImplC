#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* get_new_list_node(int data)
{
    ListNode* new_list_node = (ListNode*)malloc(sizeof(ListNode));
    new_list_node->m_data = data;
    new_list_node->m_next = NULL;
    return new_list_node;
}

LinkedList* get_new_linked_list(void)
{
    LinkedList* new_linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_linked_list->m_head = NULL;
    new_linked_list->m_tail = NULL;
    new_linked_list->m_length = 0;
    return new_linked_list;
}

void insert_after(ListNode* list_node, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_next = list_node->m_next;
    list_node->m_next = new_list_node;
}

void insert_at_head(LinkedList* linked_list, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_next = linked_list->m_head;
    linked_list->m_head = new_list_node;
    if (linked_list->m_tail == NULL)
    {
        linked_list->m_tail = new_list_node;
    }
    ++linked_list->m_length;
}

void insert_after_tail(LinkedList* linked_list, int data)
{
    if (linked_list->m_tail == NULL)
    {
        insert_at_head(linked_list, data);
    }
    else
    {
        insert_after(linked_list->m_tail, data);
        linked_list->m_tail = linked_list->m_tail->m_next;
        ++linked_list->m_length;
    }
}

void insert_at(LinkedList* linked_list, size_t index, int data)
{
    if (index > linked_list->m_length)
    {
        printf("It's not possible to insert at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, linked_list->m_length);
        abort();
    }
    if (index == 0)
    {
        insert_at_head(linked_list, data);
    }
    else if (index == linked_list->m_length)
    {
        insert_after_tail(linked_list, data);
    }
    else
    {
        ListNode* current_list_node = linked_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        insert_after(current_list_node, data);
        ++linked_list->m_length;
    }
}

void print_linked_list(LinkedList* linked_list)
{
    ListNode* current_list_node = linked_list->m_head;
    while (current_list_node != NULL)
    {
        printf("%d ", current_list_node->m_data);
        current_list_node = current_list_node->m_next;
    }
    printf("\n");
}

void delete_head(LinkedList* linked_list)
{
    if (linked_list->m_head != NULL)
    {
        ListNode* temp_list_node = linked_list->m_head;
        linked_list->m_head = temp_list_node->m_next;
        --linked_list->m_length;
        free(temp_list_node);
    }
    else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}
