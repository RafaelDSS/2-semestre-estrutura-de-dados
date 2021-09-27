#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Queue *queue, Aluno aluno) {
    Node *node = create_node();
    node->aluno = aluno;

    if (is_empty(queue)) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
    
}

void dequeue(Queue *queue) {
    Node *next;

    if (is_empty(queue))
        return;

    printf("Nome: %s\n", queue->front->aluno.nome);
    next = queue->front->next;
    free(queue->front);
    queue->front = next;

}

void empty_queue(Queue *queue) {
    Node *next;

    while (!is_empty(queue)) {
        next = queue->rear->next;
        free(queue->rear);
        queue->rear = next;
    }
    free(queue->rear);
}

int size_queue(Queue *queue) {
    Node *aux_node = queue->front;
    int count = 0;

    if (is_empty(queue))
        return 0;

    while (aux_node != NULL) {
        aux_node = aux_node->next;
        count++;
    }
    return count;
}

int is_empty(Queue *queue) {
    return (queue->front == NULL);
}

Node *create_node() {
    Node *node = (Node *)malloc(sizeof(Node));
    return node;
}