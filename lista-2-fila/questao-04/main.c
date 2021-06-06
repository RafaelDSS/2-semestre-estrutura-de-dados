#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void sort_queue(Queue *queue);

int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 10);
    enqueue(f1, 4);
    enqueue(f1, 2);
    enqueue(f1, 45);
    enqueue(f1, 21);

    sort_queue(f1);

    while (!queue_is_empty(f1))
        printf("Queue - dequeue(): %d\n", dequeue(f1));

    return 0;
}

void sort_queue(Queue *queue) {
    Queue *aux_queue = init_queue();

    enqueue(aux_queue, dequeue(queue));
    while (size_queue(queue) > 0) {
        int temp_value = dequeue(queue);

        for (int i = 0; i < size_queue(aux_queue); i++) {
            if (front_queue(aux_queue) < temp_value)
                enqueue(aux_queue, dequeue(aux_queue));
            else {
                enqueue(aux_queue, temp_value);
                temp_value = dequeue(aux_queue);
            }
        }
        enqueue(aux_queue, temp_value);
    }
    while (!queue_is_empty(aux_queue))
        enqueue(queue, dequeue(aux_queue));
}
