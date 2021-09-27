#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void push(Stack *stack, int number) {
    Node *node = create_node();

    node->number = number;
    node->previous = stack->head;
    stack->head = node;
}

int pop(Stack *stack) {
    Node *previous;
    int num;

    if (is_empty(stack))
        return 0;

    num = stack->head->number;
    previous = stack->head->previous;
    free(stack->head);
    stack->head = previous;
    return num;
}

void empty_stack(Stack *stack) {
    Node *previous;

    while (!is_empty(stack)) {
        previous = stack->head->previous;
        free(stack->head);
        stack->head = previous;
    }
    free(stack->head);
}

int size_stack(Stack *stack) {
    Node *previous;
    Stack *temp_stack = stack;
    int qt_elements = 0;

    while (!is_empty(temp_stack)) {
        previous = temp_stack->head->previous;
        temp_stack->head = previous;
        qt_elements++;
    }
    return qt_elements;
}

int is_empty(Stack *stack) {
    return (stack->head == NULL);
}

Node *create_node() {
    Node *node = (Node *)malloc(sizeof(Node));
    return node;
}