#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();
    Queue *queue = init_queue();

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 16);
    enqueue(queue, 32);

    while (!queue_is_empty(queue))
        push(stack, dequeue(queue));
    
    while (!is_empty(stack))
        enqueue(queue, pop(stack));
    
    return 0;
}