#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 10);
    enqueue(f1, 20);
    dequeue(f1);
    enqueue(f1, 30);
    enqueue(f1, 45);
    enqueue(f1, 21);
    dequeue(f1);
    dequeue(f1);

    while (!queue_is_empty(f1))
        printf("Queue - dequeue(): %d\n", dequeue(f1));

    return 0;
}
