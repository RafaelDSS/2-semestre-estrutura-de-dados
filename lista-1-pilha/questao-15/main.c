#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();
    Queue *queue = init_queue();
    int lenght_stack, lenght_queue;

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 16);
    enqueue(queue, 32);
    lenght_queue = size_queue(queue);

    for (int i = 0; i < lenght_queue; i++) {
        push(stack, dequeue(queue));
    }
    lenght_stack = size_stack(stack);

    for (int i = 0; i < lenght_queue; i++) {
        enqueue(queue, pop(stack));
    }
    
    return 0;
}