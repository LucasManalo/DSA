/*****************************************************************************
 * @author Lucas Manalo
 * @brief Source file for queue.h
 *****************************************************************************/
#include "queue.h"

void enqueue(Queue* queue, void* data) {
    qNode* node = (qNode*)malloc(sizeof(qNode));
    node->data = data;
    node->next = NULL;

    if(queue->size == 0) {
        queue->head = node;
        queue->tail = node;
        queue->size += 1;
        return;
    }

    queue->tail->next = node;
    queue->tail = node;
    return;
}

qNode* dequeue(Queue* queue) {
    if(queue->size == 0) {
        return NULL;
    }
    
    qNode* temp = queue->head;
    queue->head = temp->next;
    temp->next = NULL;
    return temp;
}

Queue* new_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void print_queue(Queue* queue, void (*print_func)(void*)) {
    for(qNode* curr = queue->head; curr != NULL; curr = curr->next) {
        print_func(curr->data);
        printf(" -> ");
    }
    printf("NULL\n");
}

void free_queue(Queue* queue) {
    while(queue->head != NULL) {
        qNode* node = dequeue(queue);
        free(node);
    }
    free(queue);
}

