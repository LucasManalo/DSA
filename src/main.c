/*****************************************************************************
 * @author Lucas Manalo
 * @brief Main fuction
 *****************************************************************************/
#include "linked_list.h"

void print_int(void* data) {
    printf("%d", *(int*)data);
}

int main() {
    LinkedList* list = new_linked_list();
    int arr[5] = {1, 2, 3, 4, 5};

    push_head(list, &arr[2]);
    push_head(list, &arr[1]);
    push_head(list, &arr[0]);
    push_tail(list, &arr[3]);
    push_tail(list, &arr[4]);

    reverse_list(list);
    print_list(list, print_int);

    remove_node(list, 4);
    remove_node(list, 2);
    remove_node(list, 0);


    // printf("%d\n", *(int*)get_node(list, 2));

    print_list(list, print_int);

    free_list(list);

    return 0;
}
