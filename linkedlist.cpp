/* LinkedList.c */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

int isEmpty(LinkedList* list) {
    return list->head == NULL;
}

void insertLast(LinkedList* list, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(list)) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    list->size++;
}

char deleteFirst(LinkedList* list) {
    if (isEmpty(list)) {
        printf("LinkedList kosong, tidak bisa menghapus.\n");
        return '\0';
    }
    
    Node* temp = list->head;
    char data = temp->data;
    list->head = list->head->next;
    free(temp);
    list->size--;
    
    return data;
}

char getFirst(LinkedList* list) {
    if (isEmpty(list)) {
        return '\0';
    }
    return list->head->data;
}

void clearList(LinkedList* list) {
    while (!isEmpty(list)) {
        deleteFirst(list);
    }
}
