#define MAX 100

typedef struct queue {
    int values[MAX];
    int front;
    int rear;
    int size;
} Queue;


Queue *init_queue();
int enqueue(Queue *queue, int number);
int dequeue(Queue *queue);
int front_queue(Queue *queue);
void empty_queue(Queue *queue);
int size_queue(Queue *queue);
int queue_is_empty(Queue *queue);
int queue_is_full(Queue *queue);
