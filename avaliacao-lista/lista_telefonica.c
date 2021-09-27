#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista_telefonica.h"


List *init_list() {
    List *list = (List *)malloc(sizeof(List));
    return list;
}

int push_front(List *list, Contato contato) {
    Node *node = create_node();

    if (node == NULL)
        return false;

    node->contato = contato;
    if (list_is_empty(list))
        list->head = node;
    else {
        node->next = list->head;
        list->head = node;
    }
    return true;
}

int push_back(List *list, Contato contato) {
    Node *node = create_node();
    Node *aux_node = list->head;

    if (node == NULL)
        return false;

    node->contato = contato;
    if (list_is_empty(list))
        push_front(list, contato);
    else {
        while (aux_node->next != NULL)
            aux_node = aux_node->next;
        aux_node->next = node;
    }
    return true;
}

int push_sorted(List *list, Contato contato) {
    Node *node = create_node();
    Node *aux_node = list->head;

    if (node == NULL)
        return false;

    node->contato = contato;
    if (list_is_empty(list) || strcmp(list->head->contato.nome, contato.nome) >= 0)
        push_front(list, contato);
    else {
        while (aux_node->next != NULL && strcmp(aux_node->contato.nome, contato.nome) < 0)
            aux_node = aux_node->next;

        node->next = aux_node->next;
        aux_node->next = node;
    }
    return true;
}

int insert_at(List *list, int position, Contato contato) {
    Node *node = create_node();
    Node *aux_node = list->head;
    int qt_positions = 0;

    node->contato = contato;
    
    if (position > size_list(list)) 
        return false;

    if (list_is_empty(list) || position == 0)
        return push_front(list, contato);

    while (qt_positions < position-1 && aux_node->next != NULL) {
        aux_node = aux_node->next;
        qt_positions++;
    }

    if (qt_positions != position-1)
        return false;
    
    if (aux_node->next == NULL)
        push_back(list, contato);
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

Contato *get_contato(Node *node) {
    Contato *contato = (Contato *)malloc(sizeof(Contato));
    *contato = node->contato;
    return contato;
}

Contato *get_front(List *list) {
    Node *node;

    node = node_front(list);
    if (node == NULL)
        return NULL;

    return get_contato(node);
}

Contato *get_back(List *list) {
    Node *node;

    node = node_back(list);
    if (node == NULL)
        return NULL;

    return get_contato(node);
}

Contato *get_at(List *list, int position) {
    Node *node;

    node = node_at(list, position);
    if (node == NULL)
        return NULL;

    if (position == 0)
        return get_contato(node);
    return get_contato(node->next);
}

bool is_the_only_node(List *list, Node *node) {
    return node == list->head;
}

Contato *pop_front(List *list) {
    Node *node;
    Contato *contato;

    node = node_front(list);
    if (node == NULL)
        return NULL;

    contato = get_contato(node);
    list->head = node->next;

    if (is_the_only_node(list, node))
        list->head = NULL;

    free(node);
    return contato;
}

Contato *pop_back(List *list) {
    Node *node;
    Contato *contato;

    node = node_back(list);
    if (node == NULL)
        return NULL;

    contato = get_contato(node);

    if (is_the_only_node(list, node))
        list->head = NULL;

    free(node);
    return contato;
}

Contato *remove_at(List *list, int position) {
    Node *node;
    Node *aux_node;
    Contato *contato;

    node = node_at(list, position);
    if (node == NULL)
        return NULL;

    if (position == 0)
        return pop_front(list);
    else {
        aux_node = node->next;
        node->next = aux_node->next;
        contato = get_contato(aux_node);
        free(node->next);
    }
    
    return contato;
}

void empty_list(List *list) {
    Node *aux_node;

    while (!list_is_empty(list)) {
        aux_node = list->head->next;
        free(list->head);
        list->head = aux_node;
    }
    free(list);
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

bool is_sorted(List *list) {
    Node *aux_node = list->head;

    if (list_is_empty(list)) 
        return true; 

    while (aux_node->next != NULL) {
        if (strcmp(aux_node->contato.nome, aux_node->next->contato.nome) > 0)
            return false;
        aux_node = aux_node->next;
    }  
    return true; 
}

bool is_full(List *list) {
    return size_list(list) == MAX;
}

int list_is_empty(List *list) {
    return list->head == NULL;
}

Node *create_node() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}
