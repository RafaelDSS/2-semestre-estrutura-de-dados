#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char matricula[20];
    char nome[30];
    float notas[3];
} Aluno;

typedef struct node {
    Aluno aluno;
    struct node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *queue, Aluno aluno);
void dequeue(Queue *queue);
void empty_queue(Queue *queue);
int size_queue(Queue *queue);
int is_empty(Queue *queue);
Node *create_node();