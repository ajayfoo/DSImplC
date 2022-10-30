#include "xor_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

ListNode* get_new_list_node(int data)
{
    ListNode* new_list_node = (ListNode*)malloc(sizeof(ListNode));
    new_list_node->m_data = data;
    new_list_node->m_diff = NULL;
    return new_list_node;
}

void init_xor_list(XORList* xor_list)
{
    xor_list->m_head = NULL;
    xor_list->m_tail = NULL;
    xor_list->m_length = 0;
}

XORList* get_new_xor_list(void)
{
    XORList* new_xor_list = (XORList*)malloc(sizeof(XORList));
    init_xor_list(new_xor_list);
    return new_xor_list;
}

ListNode* xor_of_list_nodes(const ListNode* list_node_a,
                            const ListNode* list_node_b)
{
    return (ListNode*)((size_t)list_node_a ^ (size_t)list_node_b);
}

ListNode* get_prev_list_node(const XORList* xor_list, const ListNode* list_node)
{
    ListNode* prev_list_node = NULL;
    ListNode* current_list_node = xor_list->m_head;
    ListNode* next_list_node =
        xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    while (current_list_node != list_node)
    {
        prev_list_node = current_list_node;
        current_list_node = next_list_node;
        next_list_node =
            xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    }
    return prev_list_node;
}

ListNode* get_next_list_node(const XORList* xor_list, const ListNode* list_node)
{
    ListNode* prev_list_node = NULL;
    ListNode* current_list_node = xor_list->m_head;
    ListNode* next_list_node =
        xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    while (current_list_node != list_node)
    {
        prev_list_node = current_list_node;
        current_list_node = next_list_node;
        next_list_node =
            xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    }
    return next_list_node;
}

ListNode* insert_after(XORList* xor_list, ListNode* list_node, int data)
{
    ListNode* next_list_node = get_next_list_node(xor_list, list_node);
    ListNode* prev_prev_list_node =
        xor_of_list_nodes(list_node->m_diff, next_list_node);
    ListNode* new_list_node = get_new_list_node(data);
    list_node->m_diff = xor_of_list_nodes(prev_prev_list_node, new_list_node);
    new_list_node->m_diff = xor_of_list_nodes(list_node, next_list_node);
    if (next_list_node != NULL)
    {
        ListNode* next_next_list_node =
            xor_of_list_nodes(list_node, next_list_node->m_diff);
        next_list_node->m_diff =
            xor_of_list_nodes(new_list_node, next_next_list_node);
    }
    return new_list_node;
}

void insert_at_head(XORList* xor_list, int data)
{
    ListNode* new_list_node = get_new_list_node(data);
    new_list_node->m_diff = xor_of_list_nodes(NULL, xor_list->m_head);
    if (xor_list->m_head != NULL)
    {
        ListNode* next_next_list_node =
            xor_of_list_nodes(NULL, xor_list->m_head->m_diff);
        xor_list->m_head->m_diff =
            xor_of_list_nodes(new_list_node, next_next_list_node);
    }
    xor_list->m_head = new_list_node;
    if (xor_list->m_tail == NULL)
    {
        xor_list->m_tail = xor_list->m_head;
    }
    ++xor_list->m_length;
}

void insert_after_tail(XORList* xor_list, int data)
{
    if (xor_list->m_tail == NULL)
    {
        insert_at_head(xor_list, data);
    }
    else
    {
        xor_list->m_tail = insert_after(xor_list, xor_list->m_tail, data);
        ++xor_list->m_length;
    }
}

void insert_at(XORList* xor_list, size_t index, int data)
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
        ListNode* prev_list_node = NULL;
        ListNode* current_list_node = xor_list->m_head;
        ListNode* next_list_node =
            xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
        for (size_t i = 0; i < (index - 1); ++i)
        {
            prev_list_node = current_list_node;
            current_list_node = next_list_node;
            next_list_node =
                xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
        }
        insert_after(xor_list, current_list_node, data);
        ++xor_list->m_length;
    }
}

void print_xor_list_rev(XORList* xor_list)
{
    printf("XOR Linked List in reverse order: ");
    ListNode* next_list_node = NULL;
    ListNode* current_list_node = xor_list->m_tail;
    ListNode* prev_list_node =
        xor_of_list_nodes(next_list_node, current_list_node->m_diff);
    while (current_list_node != xor_list->m_head)
    {
        printf("%d ", current_list_node->m_data);

        next_list_node = current_list_node;
        current_list_node = prev_list_node;
        prev_list_node =
            xor_of_list_nodes(next_list_node, current_list_node->m_diff);
    }
    printf("%d\n", current_list_node->m_data);
}

void print_xor_list(XORList* xor_list)
{
    printf("XOR Linked List: ");
    ListNode* prev_list_node = NULL;
    ListNode* current_list_node = xor_list->m_head;
    ListNode* next_list_node =
        xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    while (current_list_node != xor_list->m_tail)
    {
        printf("%d ", current_list_node->m_data);

        prev_list_node = current_list_node;
        current_list_node = next_list_node;
        next_list_node =
            xor_of_list_nodes(prev_list_node, current_list_node->m_diff);
    }
    printf("%d\n", current_list_node->m_data);
    print_xor_list_rev(xor_list);
}

// ListNode* delete_and_return_next_list_node(ListNode* deletion_list_node)
// {
//     ListNode* next_list_node = deletion_list_node->m_next;
//     if (deletion_list_node->m_prev != NULL)
//     {
//         deletion_list_node->m_prev->m_next = deletion_list_node->m_next;
//     }
//     if (deletion_list_node->m_next != NULL)
//     {
//         deletion_list_node->m_next->m_prev = deletion_list_node->m_prev;
//     }
//     free(deletion_list_node);
//     return next_list_node;
// }

// void clear_xor_list(XORList* xor_list)
// {
//     ListNode* current_list_node = xor_list->m_head;
//     while (current_list_node != NULL)
//     {
//         current_list_node =
//         delete_and_return_next_list_node(current_list_node);
//     }
//     xor_list->m_head = NULL;
//     xor_list->m_tail = NULL;
//     xor_list->m_length = 0;
// }

// void delete_head(XORList* xor_list)
// {
//     if (xor_list->m_head != NULL)
//     {
//         xor_list->m_head =
//         delete_and_return_next_list_node(xor_list->m_head);
//         --xor_list->m_length;
//     }
//     else
//     {
//         printf("Empty Linked List. Deletion failed.\n");
//         abort();
//     }
// }

// void delete_tail(XORList* xor_list)
// {
//     if (xor_list->m_tail != NULL)
//     {
//         if (xor_list->m_tail == xor_list->m_head)
//         {
//             clear_xor_list(xor_list);
//         }
//         else
//         {
//             ListNode* current_list_node = xor_list->m_head;
//             while (current_list_node->m_next != xor_list->m_tail)
//             {
//                 current_list_node = current_list_node->m_next;
//             }
//             current_list_node->m_next = NULL;
//             free(xor_list->m_tail);
//             xor_list->m_tail = current_list_node;
//             --xor_list->m_length;
//         }
//     }
//     else
//     {
//         printf("Empty Linked List. Deletion failed.\n");
//         abort();
//     }
// }

// void delete_at(XORList* xor_list, size_t index)
// {
//     if (index >= xor_list->m_length)
//     {
//         printf("It's not possible to delete the element at index %zu "
//                "since the length of the linked list is only %zu.\n",
//                index, xor_list->m_length);
//         abort();
//     }
//     else if (index == 0)
//     {
//         delete_head(xor_list);
//     }
//     else if (index == (xor_list->m_length - 1))
//     {
//         delete_tail(xor_list);
//     }
//     else
//     {
//         ListNode* current_list_node = xor_list->m_head;
//         for (size_t i = 0; i < (index - 1); ++i)
//         {
//             current_list_node = current_list_node->m_next;
//         }
//         ListNode* deletion_list_node = current_list_node->m_next;
//         current_list_node->m_next =
//             delete_and_return_next_list_node(deletion_list_node);
//         free(deletion_list_node);
//         --xor_list->m_length;
//     }
// }
