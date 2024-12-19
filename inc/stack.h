/*****************************************************************************
 * @author Lucas Manalo
 * @brief Header file for stack.c
 *****************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
    void* data;
    struct sNode* next;
} sNode;

typedef struct Stack {
    struct sNode* top;
    int size;
} Stack;

void push(Stack* stack, void* data);
sNode* pop(Stack* stack);
sNode* peek(Stack* stack);

Stack* new_stack();
void print_stack(Stack* stack, void (*print_func)(void*));
void free_stack(Stack* stack);

#endif // __STACK_H__