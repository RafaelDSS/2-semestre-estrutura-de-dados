#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_front(Queue *queue);

int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 10);
    enqueue(f1, 20);
    enqueue(f1, 30);
    enqueue(f1, 45);
    enqueue(f1, 21);

    printf("Queue front - dequeue(): %d\n", queue_front(f1));

    return 0;
}

int queue_front(Queue *queue) {
    return dequeue(queue);
}
