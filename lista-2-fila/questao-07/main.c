#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void) {
    Queue *f1 = init_queue();
    Queue *f2 = init_queue();

    enqueue(f1, 2);
    enqueue(f1, 4);
    enqueue(f1, -34);
    enqueue(f1, 8);

    while (!queue_is_empty(f1)) {
        int value = dequeue(f1);

        if (value > 0)
            enqueue(f2, value);
    }
    while (!queue_is_empty(f2))
        printf("Queue - dequeue(): %d\n", dequeue(f2));
        
    return 0;
}
