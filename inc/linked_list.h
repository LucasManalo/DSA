/*****************************************************************************
 * @author Lucas Manalo
 * @brief Header file for linked_list.c
 *****************************************************************************/
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct llNode {
    void* data;
    struct llNode* next;
} llNode;

typedef struct LinkedList {
    struct llNode* head;
    struct llNode* tail;
    int size;
} LinkedList;

void push_head(LinkedList* list, void* data);
void push_tail(LinkedList* list, void* data);
void* get_node(LinkedList* list, int index);
void remove_node(LinkedList* list, int index);

LinkedList* new_linked_list();
void reverse_list(LinkedList* list);
void print_list(LinkedList* list, void (*print_func)(void*));
void free_list(LinkedList* list);

#endif // __LINKED_LIST_H__