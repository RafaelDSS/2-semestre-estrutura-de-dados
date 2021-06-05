#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack *init_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = -1;
    return stack;
}

void push(Stack *stack, int value) {
    if (is_full(stack))
        return;
    stack->values[++stack->head] = value;
}

int pop(Stack *stack) {
    int value;

    if (is_empty(stack))
        return 0;
    value = stack->values[stack->head--];
    return value;
}

int top_stack(Stack *stack) {
    int value;

    if (is_empty(stack))
        return 0;
    value = stack->values[stack->head];
    return value;
}

void empty_stack(Stack *stack) {
    free(stack);
}

int size_stack(Stack *stack) {
    if (is_empty(stack))
        return 0;
    return stack->head + 1;
}

int is_empty(Stack *stack) {
    return (stack->head == -1);
}

int is_full(Stack *stack) {
    return (stack->head == MAX);
}