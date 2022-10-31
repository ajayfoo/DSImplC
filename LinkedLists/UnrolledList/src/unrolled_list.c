#include "unrolled_list.h"
#include <stdio.h>
#include <stdlib.h>

// ListNode* get_new_list_node(int data)
// {
//     ListNode* new_list_node = (ListNode*)malloc(sizeof(ListNode));
//     new_list_node->m_data = data;
//     new_list_node->m_next = NULL;
//     return new_list_node;
// }

// void insert_after(ListNode* list_node, int data)
// {
//     ListNode* new_list_node = get_new_list_node(data);
//     new_list_node->m_next = list_node->m_next;
//     list_node->m_next = new_list_node;
// }

// void insert_at_head(UnrolledList* unrolled_list, int data)
// {
//     ListNode* new_list_node = get_new_list_node(data);
//     new_list_node->m_next = unrolled_list->m_head;
//     unrolled_list->m_head = new_list_node;
//     if (unrolled_list->m_tail == NULL)
//     {
//         unrolled_list->m_tail = new_list_node;
//     }
//     ++unrolled_list->m_length;
// }

// void insert_after_tail(UnrolledList* unrolled_list, int data)
// {
//     if (unrolled_list->m_tail == NULL)
//     {
//         insert_at_head(unrolled_list, data);
//     }
//     else
//     {
//         insert_after(unrolled_list->m_tail, data);
//         unrolled_list->m_tail = unrolled_list->m_tail->m_next;
//         ++unrolled_list->m_length;
//     }
// }

// void insert_at(UnrolledList* unrolled_list, size_t index, int data)
// {
//     if (index > unrolled_list->m_length)
//     {
//         printf("It's not possible to insert at index %zu "
//                "since the length of the linked list is only %zu.\n",
//                index, unrolled_list->m_length);
//         abort();
//     }
//     if (index == 0)
//     {
//         insert_at_head(unrolled_list, data);
//     }
//     else if (index == unrolled_list->m_length)
//     {
//         insert_after_tail(unrolled_list, data);
//     }
//     else
//     {
//         ListNode* current_list_node = unrolled_list->m_head;
//         for (size_t i = 0; i < (index - 1); ++i)
//         {
//             current_list_node = current_list_node->m_next;
//         }
//         insert_after(current_list_node, data);
//         ++unrolled_list->m_length;
//     }
// }

// void print_unrolled_list(UnrolledList* unrolled_list)
// {
//     ListNode* current_list_node = unrolled_list->m_head;
//     while (current_list_node != NULL)
//     {
//         printf("%d ", current_list_node->m_data);
//         current_list_node = current_list_node->m_next;
//     }
//     printf("\n");
// }

// ListNode* delete_and_return_next_list_node(ListNode* deletion_list_node)
// {
//     ListNode* next_list_node = deletion_list_node->m_next;
//     free(deletion_list_node);
//     return next_list_node;
// }

// void clear_unrolled_list(UnrolledList* unrolled_list)
// {
//     ListNode* current_list_node = unrolled_list->m_head;
//     while (current_list_node != NULL)
//     {
//         current_list_node = delete_and_return_next_list_node(current_list_node);
//     }
//     unrolled_list->m_head = NULL;
//     unrolled_list->m_tail = NULL;
//     unrolled_list->m_length = 0;
// }

// void delete_head(UnrolledList* unrolled_list)
// {
//     if (unrolled_list->m_head != NULL)
//     {
//         unrolled_list->m_head = delete_and_return_next_list_node(unrolled_list->m_head);
//         --unrolled_list->m_length;
//     }
//     else
//     {
//         printf("Empty Linked List. Deletion failed.\n");
//         abort();
//     }
// }

// void delete_tail(UnrolledList* unrolled_list)
// {
//     if (unrolled_list->m_tail != NULL)
//     {
//         if (unrolled_list->m_tail == unrolled_list->m_head)
//         {
//             clear_unrolled_list(unrolled_list);
//         }
//         else
//         {
//             ListNode* current_list_node = unrolled_list->m_head;
//             while (current_list_node->m_next != unrolled_list->m_tail)
//             {
//                 current_list_node = current_list_node->m_next;
//             }
//             current_list_node->m_next = NULL;
//             free(unrolled_list->m_tail);
//             unrolled_list->m_tail = current_list_node;
//             --unrolled_list->m_length;
//         }
//     }
//     else
//     {
//         printf("Empty Linked List. Deletion failed.\n");
//         abort();
//     }
// }

// void delete_at(UnrolledList* unrolled_list, size_t index)
// {
//     if (index >= unrolled_list->m_length)
//     {
//         printf("It's not possible to delete the element at index %zu "
//                "since the length of the linked list is only %zu.\n",
//                index, unrolled_list->m_length);
//         abort();
//     }
//     else if (index == 0)
//     {
//         delete_head(unrolled_list);
//     }
//     else if (index == (unrolled_list->m_length - 1))
//     {
//         delete_tail(unrolled_list);
//     }
//     else
//     {
//         ListNode* current_list_node = unrolled_list->m_head;
//         for (size_t i = 0; i < (index - 1); ++i)
//         {
//             current_list_node = current_list_node->m_next;
//         }
//         ListNode* deletion_list_node = current_list_node->m_next;
//         current_list_node->m_next = current_list_node->m_next->m_next;
//         free(deletion_list_node);
//         --unrolled_list->m_length;
//     }
// }
