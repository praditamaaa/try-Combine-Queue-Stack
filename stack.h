/* Stack.h */
#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

typedef struct Stack {
    LinkedList list;
} Stack;

/* Fungsi-fungsi Stack */
void initStack(Stack* stack);
int isStackEmpty(Stack* stack);
void push(Stack* stack, char data);
char pop(Stack* stack);
char peek(Stack* stack);
void clearStack(Stack* stack);

#endif
