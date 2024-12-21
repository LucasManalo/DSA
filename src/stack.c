/*****************************************************************************
 * @author Lucas Manalo
 * @brief Source file for stack.h
 *****************************************************************************/
#include "stack.h"

void push(Stack* stack, void* data) {
    sNode* node = (sNode*)malloc(sizeof(sNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size += 1;
}

sNode* pop(Stack* stack){
    sNode* node = stack->top;
    stack->top = node->next;
    node->next = NULL;
    stack->size -= 1;
    return node;
}

sNode* peek(Stack* stack) {
    return stack->top;
}

Stack* new_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void print_stack(Stack* stack, void (*print_func)(void*)) {
    for(sNode* curr = stack->top; curr != NULL; curr = curr->next){
        print_func(curr->data);
        printf("\n");
    }  
}

void free_stack(Stack* stack) {
    while(stack->top != NULL) {
        sNode* node = pop(stack);
        free(node);
    }
    free(stack);
}