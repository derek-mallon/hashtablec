#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
typedef struct Node{
    void* obj;
    struct Node* next;
    struct Node* prev;
}Node;
typedef struct LinkedList{
    struct Node* first;
    struct Node* last;
    size_t size;
}LinkedList;
Node* LinkedList_add_node(LinkedList* list,void* obj);
void LinkedList_delete_node(LinkedList* list,Node* node);
void LinkedList_destroy(LinkedList* list);
#endif
