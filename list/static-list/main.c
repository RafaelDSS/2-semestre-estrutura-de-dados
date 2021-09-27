#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void) {
    List *list = init_list();


    push_sorted(list, 98);
    push_sorted(list, 3);
    push_sorted(list, 5);
    push_sorted(list, 4543);
    push_sorted(list, 4);
    push_sorted(list, 2);
    push_sorted(list, 45);

    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 3);
    push_front(list, 4);
    insert_at(list, 1, 30);
    pop_front(list);
    insert_at(list, 0, 737);
    remove_at(list, 2);

    return 1;
}