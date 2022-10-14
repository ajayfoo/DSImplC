#include "linked_list.h"

void test_insert_at_head(void)
{
    LinkedList* linked_list = get_new_linked_list();
    insert_at_head(linked_list, 1);
    insert_at_head(linked_list, 2);
    insert_at_head(linked_list, 3);
    insert_at_head(linked_list, 4);
    print_linked_list(linked_list);
}
