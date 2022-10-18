#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* get_new_list_node(int data)
{
    ListNode* new_list_node = (ListNode*) malloc(sizeof(ListNode));
    new_list_node->m_data = data;
    new_list_node->m_next = NULL;
    return new_list_node;
}

CircularList* get_new_circular_list(void)
{
    CircularList* new_circular_list = (CircularList*) malloc(sizeof(CircularList));
    new_circular_list->m_head = NULL;
    new_circular_list->m_tail = NULL;
    new_circular_list->m_length = 0;
    return new_circular_list;
}

void insert_at_head(CircularList* circular_list, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    if (circular_list->m_head == NULL)
    {
        new_list_node->m_next = new_list_node;
        circular_list->m_tail = new_list_node;
    } else
    {
        new_list_node->m_next = circular_list->m_head;
        circular_list->m_tail->m_next = new_list_node;
    }
    circular_list->m_head = new_list_node;
    ++circular_list->m_length;
}

void insert_after(ListNode* list_node, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_next = list_node->m_next;
    list_node->m_next = new_list_node;
}

void insert_after_tail(CircularList* circular_list, int data)
{
    if (circular_list->m_tail == NULL)
    {
        insert_at_head(circular_list, data);
    } else
    {
        insert_after(circular_list->m_tail, data);
        circular_list->m_tail = circular_list->m_tail->m_next;
        ++circular_list->m_length;
    }
}

void insert_at(CircularList* circular_list, size_t index, int data)
{
    if (index > circular_list->m_length)
    {
        printf("It's not possible to insert at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, circular_list->m_length);
        abort();
    }
    if (index == 0)
    {
        insert_at_head(circular_list, data);
    } else if (index == circular_list->m_length)
    {
        insert_after_tail(circular_list, data);
    } else
    {
        ListNode* current_list_node = circular_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        insert_after(current_list_node, data);
        ++circular_list->m_length;
    }
}

void print_circular_list(CircularList* circular_list)
{
    ListNode* current_list_node = circular_list->m_head;
    do
    {
        printf("%d ", current_list_node->m_data);
        current_list_node = current_list_node->m_next;
    } while (current_list_node != circular_list->m_head);
    printf("\n");
}

ListNode* delete_and_return_next_list_node(ListNode* deletion_list_node)
{
    ListNode* next_list_node = deletion_list_node->m_next;
    free(deletion_list_node);
    return next_list_node;
}

void clear_circular_list(CircularList* circular_list)
{
    ListNode* current_list_node = circular_list->m_head;
    while (current_list_node != NULL)
    {
        current_list_node = delete_and_return_next_list_node(current_list_node);
    }
    circular_list->m_head = NULL;
    circular_list->m_head = NULL;
    circular_list->m_length = 0;
}

void delete_head(CircularList* circular_list)
{
    if (circular_list->m_head != NULL)
    {
        circular_list->m_head = delete_and_return_next_list_node(circular_list->m_head);
        --circular_list->m_length;
    } else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_tail(CircularList* circular_list)
{
    if (circular_list->m_tail != NULL)
    {
        if (circular_list->m_tail == circular_list->m_head)
        {
            clear_circular_list(circular_list);
        } else
        {
            ListNode* current_list_node = circular_list->m_head;
            while (current_list_node->m_next != circular_list->m_tail)
            {
                current_list_node = current_list_node->m_next;
            }
            current_list_node->m_next = NULL;
            free(circular_list->m_tail);
            circular_list->m_tail = current_list_node;
            --circular_list->m_length;
        }
    } else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_at(CircularList* circular_list, size_t index)
{
    if (index >= circular_list->m_length)
    {
        printf("It's not possible to delete the element at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, circular_list->m_length);
        abort();
    } else if (index == 0)
    {
        delete_head(circular_list);
    } else if (index == (circular_list->m_length - 1))
    {
        delete_tail(circular_list);
    } else
    {
        ListNode* current_list_node = circular_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        ListNode* deletion_list_node = current_list_node->m_next;
        current_list_node->m_next = current_list_node->m_next->m_next;
        free(deletion_list_node);
        --circular_list->m_length;
    }
}
