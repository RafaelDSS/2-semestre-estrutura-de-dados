#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue *join_queues(Queue *f1, Queue *f2);

int main(void) {
    Queue *f1 = init_queue();
    Queue *f2 = init_queue();
    Queue *f3 = init_queue();

    enqueue(f1, 32);
    enqueue(f1, 15);
    enqueue(f1, 75);
    enqueue(f1, 8);

    enqueue(f2, 6);
    enqueue(f2, 2);
    enqueue(f2, 4);
    enqueue(f2, 86);
    enqueue(f2, 50);

    f3 = join_queues(f1, f2);

    while (!queue_is_empty(f3))
        printf("Queue - dequeue(): %d\n", dequeue(f3));

    return 0;
}

Queue *join_queues(Queue *f1, Queue *f2) {
    Queue *f3 = init_queue();
    int value_f1, value_f2, aux;

    while (!queue_is_empty(f1) || !queue_is_empty(f2)) {
        value_f1 = dequeue(f1);
        value_f2 = dequeue(f2);

        if (value_f1 > value_f2) {
            aux = value_f2;
            value_f2 = value_f1;
            value_f1 = aux;
        }

        if (value_f1)
            enqueue(f3, value_f1);
        if (value_f2)
            enqueue(f3, value_f2);
    }
    return f3;
}
