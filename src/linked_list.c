/*****************************************************************************
 * @author Lucas Manalo
 * @brief Source file for linked_list.h
 *****************************************************************************/
#include "linked_list.h"

void push_head(LinkedList* list, void* data) {
    // Create new node
    llNode* node = (llNode*)malloc(sizeof(llNode)); 
    node->data = data;
    node->next = list->head;
    
    // Adjust list object
    list->head = node;
    if(list->size == 0) {
        list->tail = node;
    }
    list->size += 1;
}

void push_tail(LinkedList* list, void* data) {
    // Create new node
    llNode* node = (llNode*)malloc(sizeof(llNode)); 
    node->data = data;
    node->next = NULL;
    
    // Adjust list object
    if(list->size == 0) {
        list->head = node;
        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size += 1;
}

void* get_node(LinkedList* list, int index) {
    // Check bounds of list
    if(index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return NULL;
    }

    // Find node in list
    llNode* curr = list->head;
    for(int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void remove_node(LinkedList* list, int index) {
    // Check bounds of list
    if(index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return NULL;
    }

    // Find node of list
    llNode* curr = list->head;
    llNode* prev = NULL;
    for(int i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    // Handle removing head, tail, or other node
    if(curr == list->head) {
        list->head = list->head->next;
        curr->next = NULL;
    }
    else if(curr == list->tail) {
        list->tail = prev;
        prev->next = NULL;
    }
    else {
        prev->next = curr->next;
    }

    // Detach and remove curr
    curr->next = NULL;
    free(curr);
    list->size -= 1;
}

LinkedList* new_linked_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;    
    return list;
}

void reverse_list(LinkedList* list) {
    // Break early on empty/single item lists
    if (list->size <= 1) {
        return;
    }

    // Linked list reversal
    llNode* prev = NULL;
    llNode* curr = list->head;
    llNode* next = NULL;
    list->tail = list->head;
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;       
    }
    list->head = prev;
}

void print_list(LinkedList* list, void (*print_func)(void*)) {
    for(llNode* curr = list->head; curr != NULL; curr = curr->next) {
        print_func(curr->data);
        printf(" -> ");
    }
    printf("NULL\n");
}

void free_list(LinkedList* list) {
    while(list->head != NULL) {
        remove_node(list, 0);
    }
    free(list);
}

