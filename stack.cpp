/* Stack.c */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack(Stack* stack) {
    initLinkedList(&stack->list);
}

int isStackEmpty(Stack* stack) {
    return isEmpty(&stack->list);
}

void push(Stack* stack, char data) {
    insertLast(&stack->list, data);
}

char pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack kosong, tidak bisa melakukan pop.\n");
        return '\0';
    }
    
    Node* temp = stack->list.head;
    
    // Jika hanya ada satu elemen
    if (temp->next == NULL) {
        return deleteFirst(&stack->list);
    }
    
    // Mencari node kedua terakhir
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    Node* last = temp->next;
    char data = last->data;
    
    temp->next = NULL;
    free(last);
    stack->list.size--;
    
    return data;
}

char peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        return '\0';
    }
    
    Node* temp = stack->list.head;
    
    // Mencari node terakhir
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    return temp->data;
}

void clearStack(Stack* stack) {
    clearList(&stack->list);
}
