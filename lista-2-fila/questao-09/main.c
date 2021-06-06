#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void print_queue(Queue *queue);

int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 2);
    enqueue(f1, 4);
    enqueue(f1, 34);
    enqueue(f1, 88);

    print_queue(f1);
    
    return 0;
}

void print_queue(Queue *f1) {
    while (!queue_is_empty(f1))
        printf("Queue - dequeue(): %d\n", dequeue(f1));
}
