#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"


List *init_list() {
    List *list = (List *)malloc(sizeof(List));
    return list;
}

int push_front(List *list, Aluno aluno) {
    Node *node = create_node();

    if (node == NULL)
        return false;

    node->aluno = aluno;
    if (list_is_empty(list))
        list->head = node;
    else {
        node->next = list->head;
        list->head = node;
    }
    return true;
}

int push_back(List *list, Aluno aluno) {
    Node *node = create_node();
    Node *aux_node = list->head;

    if (node == NULL)
        return false;

    node->aluno = aluno;
    if (list_is_empty(list))
        push_front(list, aluno);
    else {
        while (aux_node->next != NULL)
            aux_node = aux_node->next;
        aux_node->next = node;
    }
    return true;
}

int push_sorted(List *list, Aluno aluno) {
    Node *node = create_node();
    Node *aux_node = list->head;

    if (node == NULL)
        return false;

    node->aluno = aluno;
    if (list_is_empty(list) || strcmp(list->head->aluno.matricula, aluno.matricula) >= 0)
        push_front(list, aluno);
    else {
        while (aux_node->next != NULL && strcmp(aux_node->aluno.matricula, aluno.matricula) < 0)
            aux_node = aux_node->next;

        node->next = aux_node->next;
        aux_node->next = node;
    }
    return true;
}

int insert_at(List *list, int position, Aluno aluno) {
    Node *node = create_node();
    Node *aux_node = list->head;
    int qt_positions = 0;

    node->aluno = aluno;
    
    if (position > size_list(list)) 
        return false;

    if (list_is_empty(list) || position == 0)
        return push_front(list, aluno);

    while (qt_positions < position-1 && aux_node->next != NULL) {
        aux_node = aux_node->next;
        qt_positions++;
    }

    if (qt_positions != position-1)
        return false;
    
    if (aux_node->next == NULL)
        push_back(list, aluno);
    else {
        node->next = aux_node->next;
        aux_node->next = node;
    }
    return true;
}

Node *node_front(List *list) {

    if (list_is_empty(list))
        return NULL;

    return list->head;
}

Node *node_back(List *list) {
    Node *aux_node = list->head;

    if (list_is_empty(list))
        return node_front(list);

    while (aux_node->next != NULL)
        aux_node = aux_node->next;

    return aux_node;
}

Node *node_at(List *list, int position) {
    Node *aux_node = list->head;
    int qt_positions = 0;

    if (list_is_empty(list) || position > size_list(list) - 1)
        return NULL;
    
    if (position == 0)
        return aux_node;

    while (qt_positions < position-1 && aux_node->next != NULL) {
        aux_node = aux_node->next;
        qt_positions++;
    }

    if (qt_positions != position-1)
        return NULL;
    return aux_node;
}

Aluno *get_aluno(Node *node) {
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    *aluno = node->aluno;
    return aluno;
}

Aluno *get_front(List *list) {
    Node *node;

    node = node_front(list);
    if (node == NULL)
        return NULL;

    return get_aluno(node);
}

Aluno *get_back(List *list) {
    Node *node;

    node = node_back(list);
    if (node == NULL)
        return NULL;

    return get_aluno(node);
}

Aluno *get_at(List *list, int position) {
    Node *node;

    node = node_at(list, position);
    if (node == NULL)
        return NULL;

    if (position == 0)
        return get_aluno(node);
    return get_aluno(node->next);
}

bool is_only_first_node(List *list, Node *node) {
    return node == list->head;
}

Aluno *pop_front(List *list) {
    Node *node;
    Aluno *aluno;

    node = node_front(list);
    if (node == NULL)
        return NULL;

    aluno = get_aluno(node);
    list->head = node->next;

    if (is_only_first_node(list, node))
        list->head = NULL;

    free(node);
    return aluno;
}

Aluno *pop_back(List *list) {
    Node *node;
    Aluno *aluno;

    node = node_back(list);
    if (node == NULL)
        return NULL;

    aluno = get_aluno(node);

    if (is_only_first_node(list, node))
        list->head = NULL;

    free(node);
    return aluno;
}

Aluno *remove_at(List *list, int position) {
    Node *node;
    Node *aux_node;
    Aluno *aluno;

    node = node_at(list, position);
    if (node == NULL)
        return NULL;

    if (position == 0)
        return pop_front(list);
    else {
        aux_node = node->next;
        node->next = aux_node->next;
        aluno = get_aluno(aux_node);
        free(node->next);
    }
    
    return aluno;
}

void empty_list(List *list) {
    Node *aux_node;

    while (!list_is_empty(list)) {
        aux_node = list->head->next;
        free(list->head);
        list->head = aux_node;
    }
    free(list->head);
}

int size_list(List *list) {
    Node *aux_node = list->head;
    int count = 0;

    if (list_is_empty(list))
        return 0;

    while (aux_node != NULL) {
        aux_node = aux_node->next;
        count++;
    }
    return count;
}

int list_is_empty(List *list) {
    return list->head == NULL;
}

Node *create_node() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}
