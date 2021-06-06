#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void concat_queues(Queue *f1, Queue *f2);

int main(void) {
    Queue *f1 = init_queue();
    Queue *f2 = init_queue();

    enqueue(f1, 2);
    enqueue(f1, 4);
    enqueue(f1, 34);
    enqueue(f1, 88);

    enqueue(f2, 4);
    enqueue(f2, 5);
    enqueue(f2, 64);
    enqueue(f2, 86);
    enqueue(f2, 500);

    concat_queues(f1, f2);

    while (!queue_is_empty(f1))
        printf("Queue - dequeue(): %d\n", dequeue(f1));

    return 0;
}

void concat_queues(Queue *f1, Queue *f2) {
    while (!queue_is_empty(f2))
        enqueue(f1, dequeue(f2));
}
