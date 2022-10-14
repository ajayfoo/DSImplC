#include "linked_list.h"

void test_print_linked_list(void)
{
    LinkedList* linked_list = get_new_linked_list();
    insert_at(linked_list, 0, 1);
    insert_after_tail(linked_list, 2);
    insert_after_tail(linked_list, 3);
    print_linked_list(linked_list);
}
