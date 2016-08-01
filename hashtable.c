#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedlist.h"
#include "hashtable.h"
const size_t SMALL_PRIME = 31;
typedef enum{false,true} bool;
typedef struct Pair{
    void* obj;
    uint8_t* key;
    size_t key_size;
}Pair;
size_t prime(size_t range){
    uint8_t* numbs = calloc(range+1,sizeof(uint8_t));
    size_t i;
    size_t counter = 1;
    size_t step = 2;
    while(counter){
        counter = 0;
        for(i=step*2;i<range+1;i += step){
            if(numbs[i] == 0){
                counter++;
                numbs[i] = 1;
            }
        }
        for(i=step+1;i<range+1;i++){
            if(numbs[i] == 0){
                step = i;
                break;
            }
        }
    }
    for(i=range;i>1;i--){
        if(numbs[i] == 0){
            return i;
        }
    }
    return 2;
}
Hashtable Hastable_create(size_t min_keys){
    Hashtable hashtable;
    hashtable.prime = prime(min_keys);
    size_t i;
    for(i=1; hashtable.prime< min_keys;i++){
        hashtable.prime = prime(min_keys + (100*i));
    }
    hashtable.chains = calloc(hashtable.prime,sizeof(LinkedList));
    return hashtable;
}
size_t find_hash(uint8_t* key,size_t key_size,size_t prime){
    size_t hash = 0;
    int i;
    for(i=0;i<key_size;i++){
        hash = (SMALL_PRIME * hash + key[i]) % prime;
    }
    return hash;
}
size_t find_string_hash(char* key,size_t prime){
    size_t hash = 0;
    char* ptr = key;
    while(*ptr){
        hash = (SMALL_PRIME * hash + *ptr++) % prime;
    }
    return hash;
}
void Hashtable_insert_pair(Hashtable* hashtable,uint8_t* key,size_t key_size,void* obj){
    Pair* pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->key_size = key_size;
    pair->obj = obj;
    size_t hash = find_hash(key,key_size,hashtable->prime);
    LinkedList_add_node(&hashtable->chains[hash],pair);
}
void HashtableString_insert_pair(Hashtable* hashtable,char* key,void* obj){
    Pair* pair = malloc(sizeof(Pair));
    size_t key_size = 0;
    pair->key = (uint8_t*)key;
    pair->key_size = key_size;
    pair->obj = obj;
    size_t hash = find_hash(pair->key,key_size,hashtable->prime);
    LinkedList_add_node(&hashtable->chains[hash],pair);
}
void* Hashtable_lookup_obj(Hashtable* hashtable,uint8_t* key,size_t key_size){
    size_t hash = find_hash(key,key_size,hashtable->prime);
    int i;
    if(hashtable->chains[hash].size != 0){
        bool found;
        Node* look_up = hashtable->chains[hash].first;
        while(look_up){
            found = true;
            Pair* check_pair = (Pair*)look_up->obj;
            for(i=0;i<key_size;i++){
                if(check_pair->key[i] != key[i]){
                    found = false;
                    break;
                }
            }
            if(found){
                return check_pair->obj;
            }
        }
    }
    return NULL;
}
void* HashtableString_lookup_obj(Hashtable* hashtable,char* key){
    size_t key_size = 0;
    while(*key++){
        key_size++;
    }
    size_t hash = find_hash((uint8_t*)key,key_size,hashtable->prime);
    int i;
    if(hashtable->chains[hash].size != 0){
        bool found;
        Node* look_up = hashtable->chains[hash].first;
        while(look_up){
            found = true;
            Pair* check_pair = (Pair*)look_up->obj;
            for(i=0;i<key_size;i++){
                if(check_pair->key[i] != key[i]){
                    found = false;
                    break;
                }
            }
            if(found){
                return check_pair->obj;
            }
        }
    }
    return NULL;
}
size_t hash_int(size_t key,size_t prime){
    return key % prime;
}
