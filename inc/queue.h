/*****************************************************************************
 * @author Lucas Manalo
 * @brief Header file for queue.c
 *****************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct qNode {
    void* data;
    struct qNode* next;
} qNode;

typedef struct Queue {
    struct qNode* head;
    struct qNode* tail;
    int size;
} Queue;

/* HEAD -> NODE -> NODE -> TAIL -> NULL
 * Enqueue adds node to end (replaces tail)
 * dequeue removes node from front (removes head) */
void enqueue(Queue* queue, void* data);
qNode* dequeue(Queue* queue);

Queue* new_queue();
void print_queue(Queue* queue, void (*print_func)(void*));
void free_queue(Queue* queue);

#endif // __QUEUE_H__