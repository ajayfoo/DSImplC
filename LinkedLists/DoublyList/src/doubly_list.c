#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* get_new_list_node(int data)
{
    ListNode* new_list_node = (ListNode*) malloc(sizeof(ListNode));
    new_list_node->m_data = data;
    new_list_node->m_next = NULL;
    new_list_node->m_prev = NULL;
    return new_list_node;
}

void init_doubly_list(DoublyList* doubly_list)
{
    doubly_list->m_head = NULL;
    doubly_list->m_tail = NULL;
    doubly_list->m_length = 0;
}

DoublyList* get_new_doubly_list(void)
{
    DoublyList* new_doubly_list = (DoublyList*) malloc(sizeof(DoublyList));
    new_doubly_list->m_head = NULL;
    new_doubly_list->m_tail = NULL;
    new_doubly_list->m_length = 0;
    return new_doubly_list;
}

void insert_after(ListNode* list_node, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_next = list_node->m_next;
    new_list_node->m_prev = list_node;
    if (list_node->m_next != NULL)
    {
        list_node->m_next->m_prev = new_list_node;
    }
    list_node->m_next = new_list_node;
}

void insert_at_head(DoublyList* doubly_list, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_next = doubly_list->m_head;
    if (doubly_list->m_head != NULL)
    {
        doubly_list->m_head->m_prev = new_list_node;
    }
    doubly_list->m_head = new_list_node;
    if (doubly_list->m_tail == NULL)
    {
        doubly_list->m_tail = doubly_list->m_head;
    }
    ++doubly_list->m_length;
}

void insert_after_tail(DoublyList* doubly_list, int data)
{
    if (doubly_list->m_tail == NULL)
    {
        insert_at_head(doubly_list, data);
    } else
    {
        insert_after(doubly_list->m_tail, data);
        doubly_list->m_tail = doubly_list->m_tail->m_next;
        ++doubly_list->m_length;
    }
}

void insert_at(DoublyList* doubly_list, size_t index, int data)
{
    if (index > doubly_list->m_length)
    {
        printf("It's not possible to insert at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, doubly_list->m_length);
        abort();
    }
    if (index == 0)
    {
        insert_at_head(doubly_list, data);
    } else if (index == doubly_list->m_length)
    {
        insert_after_tail(doubly_list, data);
    } else
    {
        ListNode* current_list_node = doubly_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        insert_after(current_list_node, data);
        ++doubly_list->m_length;
    }
}

void print_doubly_list_rev(DoublyList* doubly_list)
{
    printf("Doubly Linked List in reverse order: ");
    ListNode* current_list_node = doubly_list->m_tail;
    while (current_list_node != NULL)
    {
        printf("%d ", current_list_node->m_data);
        current_list_node = current_list_node->m_prev;
    }
    printf("\n");
}

void print_doubly_list(DoublyList* doubly_list)
{
    printf("Doubly Linked List: ");
    ListNode* current_list_node = doubly_list->m_head;
    while (current_list_node != NULL)
    {
        printf("%d ", current_list_node->m_data);
        current_list_node = current_list_node->m_next;
    }
    printf("\n");
    print_doubly_list_rev(doubly_list);
}

ListNode* delete_and_return_next_list_node(ListNode* deletion_list_node)
{
    ListNode* next_list_node = deletion_list_node->m_next;
    if (deletion_list_node->m_prev != NULL)
    {
        deletion_list_node->m_prev->m_next = deletion_list_node->m_next;
    }
    if (deletion_list_node->m_next != NULL)
    {
        deletion_list_node->m_next->m_prev = deletion_list_node->m_prev;
    }
    free(deletion_list_node);
    return next_list_node;
}

void clear_doubly_list(DoublyList* doubly_list)
{
    ListNode* current_list_node = doubly_list->m_head;
    while (current_list_node != NULL)
    {
        current_list_node = delete_and_return_next_list_node(current_list_node);
    }
    doubly_list->m_head = NULL;
    doubly_list->m_tail = NULL;
    doubly_list->m_length = 0;
}

void delete_head(DoublyList* doubly_list)
{
    if (doubly_list->m_head != NULL)
    {
        doubly_list->m_head = delete_and_return_next_list_node(doubly_list->m_head);
        --doubly_list->m_length;
    } else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_tail(DoublyList* doubly_list)
{
    if (doubly_list->m_tail != NULL)
    {
        if (doubly_list->m_tail == doubly_list->m_head)
        {
            clear_doubly_list(doubly_list);
        } else
        {
            ListNode* current_list_node = doubly_list->m_head;
            while (current_list_node->m_next != doubly_list->m_tail)
            {
                current_list_node = current_list_node->m_next;
            }
            current_list_node->m_next = NULL;
            free(doubly_list->m_tail);
            doubly_list->m_tail = current_list_node;
            --doubly_list->m_length;
        }
    } else
    {
        printf("Empty Linked List. Deletion failed.\n");
        abort();
    }
}

void delete_at(DoublyList* doubly_list, size_t index)
{
    if (index >= doubly_list->m_length)
    {
        printf("It's not possible to delete the element at index %zu "
               "since the length of the linked list is only %zu.\n",
               index, doubly_list->m_length);
        abort();
    } else if (index == 0)
    {
        delete_head(doubly_list);
    } else if (index == (doubly_list->m_length - 1))
    {
        delete_tail(doubly_list);
    } else
    {
        ListNode* current_list_node = doubly_list->m_head;
        for (size_t i = 0; i < (index - 1); ++i)
        {
            current_list_node = current_list_node->m_next;
        }
        ListNode* deletion_list_node = current_list_node->m_next;
        current_list_node->m_next = delete_and_return_next_list_node(deletion_list_node);
        free(deletion_list_node);
        --doubly_list->m_length;
    }
}
