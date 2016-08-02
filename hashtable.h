#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <linkedlist.h>
#include <stdint.h>
typedef struct Hashtable{
    LinkedList* chains;
    size_t prime;
}Hashtable;
Hashtable Hashtable_create(size_t min_keys);
void Hashtable_insert_pair(Hashtable* hashtable,uint8_t* key,size_t key_size,void* obj);
void* Hashtable_lookup_obj(Hashtable* hashtable,uint8_t* key,size_t key_size);
void HashtableString_insert_pair(Hashtable* hashtable,char* key,void* obj);
void* HashtableString_lookup_obj(Hashtable* hashtable,char* key);
void Hashtable_destroy(Hashtable* hashtable);
#endif
