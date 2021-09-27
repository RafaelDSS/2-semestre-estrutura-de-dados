#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *init_list() {
    List *list = (List *)malloc(sizeof(List));
    list->size = 0;
    return list;
}

void shift_right(List *list, int position) {
    for (int i = size_list(list) - 1; i >= position; i--) {
        list->values[i+1] = list->values[i];
    }
}

void shift_left(List *list, int position) {
    for (int i = position; i < size_list(list) - 1; i++) {
        list->values[i] = list->values[i+1];
    }
}

int push_front(List *list, int number) {
    if (list_is_full(list))
        return 0;
    if (!list_is_empty(list))
        shift_right(list, 0);
    list->size++;
    list->values[0] = number;
    return 1;
}

int push_back(List *list, int number) {
    if (list_is_full(list))
        return 0;
    list->values[list->size++] = number;
    return 1;
}

int insert_at(List *list, int position, int number) {
    if (list_is_full(list))
        return 0;
    else if (position > size_list(list))
        return 0;
    if (!list_is_empty(list))
        shift_right(list, position);
    list->values[position] = number;
    list->size++;
    return 1;
}

int position_sorted(List *list, int number) {
    for (int i = 0; i < size_list(list); i++) {
        if (number < list->values[i])
            return i;
    }
    return size_list(list);
}

int push_sorted(List *list, int number) {
    if (list_is_full(list))
        return 0;
    else if (list_is_empty(list))
        push_front(list, number);
    else
        insert_at(list, position_sorted(list, number), number);
    return 1;
}

int pop_front(List *list) {
    int value;

    if (list_is_empty(list))
        return 0;
    value = list->values[0];
    shift_left(list, 0);
    list->size--;
    return value;
}

int pop_back(List *list) {
    if (list_is_empty(list))
        return 0;
    return list->values[--list->size];
}

int remove_at(List *list, int index) {
    if (list_is_empty(list))
        return 0;
    else if (index == 0)
        return pop_front(list);
    else if (index == size_list(list) - 1)
        return pop_back(list);
    
    if (!list_is_empty(list))
        shift_left(list, index);
    return list->values[index];
}

void empty_list(List *list) {
    free(list);
}

int size_list(List *list) {
    return list->size;
}

int list_is_empty(List *list) {
    return (list->size == 0);
}

int list_is_full(List *list) {
    return (list->size == MAX);
}