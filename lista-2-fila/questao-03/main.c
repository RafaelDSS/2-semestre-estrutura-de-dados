#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"


void reverse_queue(Queue *queue);

int main(void) {
    Queue *queue = init_queue();

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 34);
    enqueue(queue, 8);

    reverse_queue(queue);

    while (!queue_is_empty(queue))
        printf("Queue - dequeue(): %d\n", dequeue(queue));

    return 0;
}

void reverse_queue(Queue *queue) {
    Stack *stack = init_stack();

    while (!queue_is_empty(queue))
        push(stack, dequeue(queue));

    while (!is_empty(stack))
        enqueue(queue, pop(stack));
}
