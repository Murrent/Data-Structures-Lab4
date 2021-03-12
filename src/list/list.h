// Martin Vickgren, Samson Tesfalem

#ifndef LAB1_ALGORITHM_LIST_H
#define LAB1_ALGORITHM_LIST_H


typedef struct node_
{
    struct node_* previous;
    struct node_* next;
    int key;
}Node;
typedef struct list_
{
    Node* head;
    Node* tail;
    int length;
}List;

List* createList();
Node* createNode(int key);
int printList(List* list);
int printListBackwards(List* list);
int isEmpty(List* list);
int insert(List* list, Node* node);
Node* search(List* list, int key);
Node* detachNode(List* list, Node* node);
Node* maximum(List* list);
Node* minimum(List* list);
Node* successor(List* list, Node* node);
Node* predecessor(List* list, Node* node);
int freeList(List* list);
int freeNode(Node* node);

#endif //LAB1_ALGORITHM_LIST_H
