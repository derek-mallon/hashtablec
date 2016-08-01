#include "linkedlist.h"
Node* LinkedList_add_node(LinkedList* list,void* obj){
    Node* node = malloc(sizeof(node));
    node->obj = obj;
    if(list->last){
        list->last->next = node;
        node->prev = list->last;
    }else{
        node->prev = NULL;
        list->first = node;
    }
    node->next = NULL;
    list->last = node;
    list->size++;
    return node;
}
void LinkedList_delete_node(LinkedList* list,Node* node){
    if(node->prev)
        node->prev->next = node->next;
    else
        list->first = node->next;
    if(!node->next)
        list->last = node->prev;
    free(node);
    list->size--;
}
void LinkedList_destroy_linked_list(LinkedList* list){
    int i;
    Node* node1 = list->first;
    Node* node2;
    for(i=0;i<list->size;i++){
        node2 = node1->next;
        free(node1);
        node1 = node2;
    }
}
