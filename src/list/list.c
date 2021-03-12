// Martin Vickgren, Samson Tesfalem

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

int printList(List* list) {
    if (list == NULL || isEmpty(list)) return 0;
    Node* node = list->head;
    for (; node; node = node->next)
        printf("%d\n", node->key);
    return 1;
}

int printListBackwards(List* list) {
    if (list == NULL || isEmpty(list)) return 0;
    Node* node = list->tail;
    for (; node; node = node->previous)
        printf("%d\n", node->key);
    return 1;
}

int isEmpty(List* list) {
    if (list == NULL) return 0;
    return list->head == NULL;
}

int insert(List* list, Node* node) {
    if (list == NULL || node == NULL) return 0;
    if (list->head == NULL)
        list->tail = node;
    else
        list->head->previous = node;

    node->next = list->head;
    node->previous = NULL;
    list->head = node;
    list->length++;
    return 1;
}

Node* search(List* list, int key) {
    if (list == NULL)
        return NULL;
    Node* tmp = list->head;
    for (; tmp; tmp = tmp->next)
        if (tmp->key == key) return tmp;
    return NULL;
}

Node* detachNode(List* list, Node* node) {
    if (list == NULL || node == NULL)
        return NULL;
    if (node->previous != NULL)
        node->previous->next = node->next;
    else list->head = node->next;
    if (node->next != NULL)
        node->next->previous = node->previous;
    else list->tail = node->previous;
    list->length--;
    return node;
}

Node* maximum(List* list) {
    if (list == NULL)
        return NULL;
    Node* tmp = list->head;
    Node* max = tmp;
    for (; tmp; tmp = tmp->next)
        if (max->key < tmp->key) max = tmp;
    return max;
}

Node* minimum(List* list) {
    if (list == NULL)
        return NULL;
    Node* tmp = list->head;
    Node* min = tmp;
    for (; tmp; tmp = tmp->next)
        if (min->key > tmp->key) min = tmp;
    return min;
}

Node* successor(List* list, Node* node) {
    if (list == NULL || node == NULL)
        return NULL;
    Node* tmp = list->head;
    Node* found = NULL;
    for (; tmp; tmp = tmp->next){
        if (tmp->key > node->key) {
            if (found == NULL || (found->key > tmp->key))
                found = tmp;
        }
    }
    return found;
}

Node* predecessor(List* list, Node* node) {
    if (list == NULL || node == NULL)
        return NULL;
    Node* tmp = list->head;
    Node* found = NULL;
    for (; tmp; tmp = tmp->next){
        if (tmp->key < node->key) {
            if (found == NULL || (found->key < tmp->key))
                found = tmp;
        }
    }
    return found;
}

int freeList(List* list) {
    if (list == NULL) return 0;
    Node* tmp = list->head;
    Node* toFree = NULL;
    for (; tmp;){
        toFree = tmp;
        tmp = tmp->next;
        free(toFree);
    }
    free(list);
    return 1;
}

int freeNode(Node* node) {
    if (node == NULL) return 0;
    free(node);
    return 1;
}
