#include "stack.h"

#define MAX 100

typedef struct queue {
    Stack *pointers[MAX];
    int front;
    int rear;
    int size;
} Queue;


Queue *init_queue();
int enqueue(Queue *queue, Stack *stack);
Stack *dequeue(Queue *queue);
void empty_queue(Queue *queue);
int size_queue(Queue *queue);
int queue_is_empty(Queue *queue);
int queue_is_full(Queue *queue);
