#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue *init_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int enqueue(Queue *queue, int number) {
    if (queue_is_full(queue))
        return 0;
    if (queue_is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    queue->size++;
    queue->values[queue->rear++] = number;
    return 1;
}

int dequeue(Queue *queue) {
    if (queue_is_empty(queue))
        return 0;
    queue->size--;
    return queue->values[queue->front++];
}

int front_queue(Queue *queue) {
    if (queue_is_empty(queue))
        return 0;
    return queue->values[queue->front];
}

void empty_queue(Queue *queue) {
    free(queue);
}

int size_queue(Queue *queue) {
    return queue->size;
}

int queue_is_empty(Queue *queue) {
    return (queue->size == 0);
}

int queue_is_full(Queue *queue) {
    return (queue->size == MAX);
}