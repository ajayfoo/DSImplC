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
    CircularList* new_circular_list = malloc(sizeof(CircularList));
    new_circular_list->m_tail = NULL;
    new_circular_list->m_length = 0;
    return new_circular_list;
}

void check_for_null(const CircularList* circular_list)
{
    if (circular_list == NULL)
    {
        printf("NULL passed instead of a circular list. Exiting...\n");
        abort();
    }
}

void check_for_null_and_empty_list(const CircularList* circular_list)
{
    check_for_null(circular_list);
    if (circular_list->m_tail == NULL)
    {
        printf("Empty list passed instead of non-empty list."
               "\nExiting...\n");
        abort();
    }
}

void insert_at_head(CircularList* circular_list, int data)
{
    check_for_null(circular_list);
    ListNode* new_list_node = get_new_list_node(data);
    if (circular_list->m_tail == NULL)
    {
        new_list_node->m_next = new_list_node;
        circular_list->m_tail = new_list_node;
    } else
    {
        new_list_node->m_next = circular_list->m_tail->m_next;
        circular_list->m_tail->m_next = new_list_node;
    }
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
    check_for_null(circular_list);
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
    check_for_null(circular_list);
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
        ListNode* current_list_node = circular_list->m_tail->m_next;
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
    check_for_null(circular_list);
    if (circular_list->m_tail != NULL)
    {
        ListNode* current_list_node = circular_list->m_tail->m_next;
        do
        {
            printf("%d ", current_list_node->m_data);
            current_list_node = current_list_node->m_next;
        } while (current_list_node != circular_list->m_tail->m_next);
    }
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
    check_for_null_and_empty_list(circular_list);
    ListNode* head_node = circular_list->m_tail->m_next;
    ListNode* current_list_node = head_node;
    do
    {
        current_list_node = delete_and_return_next_list_node(current_list_node);
    } while (current_list_node != head_node);
    circular_list->m_tail = NULL;
    circular_list->m_length = 0;
    free(circular_list);
    circular_list=NULL;
}

void delete_head(CircularList* circular_list)
{
    check_for_null_and_empty_list(circular_list);
    if (circular_list->m_tail == circular_list->m_tail->m_next)
    {
        free(circular_list->m_tail);
        circular_list->m_tail = NULL;
    } else
    {
        circular_list->m_tail->m_next = delete_and_return_next_list_node(circular_list->m_tail->m_next);
    }
    --circular_list->m_length;
}

void delete_tail(CircularList* circular_list)
{
    check_for_null_and_empty_list(circular_list);
    if (circular_list->m_tail == circular_list->m_tail->m_next)
    {
        clear_circular_list(circular_list);
    } else
    {
        ListNode* current_list_node = circular_list->m_tail->m_next;
        do
        {
            current_list_node = current_list_node->m_next;
        } while (current_list_node->m_next != circular_list->m_tail);
        current_list_node->m_next = circular_list->m_tail->m_next;
        free(circular_list->m_tail);
        circular_list->m_tail = current_list_node;
        --circular_list->m_length;
    }
}

void delete_at(CircularList* circular_list, size_t index)
{
    check_for_null_and_empty_list(circular_list);
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
        ListNode* current_list_node = circular_list->m_tail->m_next;
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
