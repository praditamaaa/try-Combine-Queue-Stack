/* LinkedList.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

/* Fungsi-fungsi dasar LinkedList */
void initLinkedList(LinkedList* list);
int isEmpty(LinkedList* list);
void insertLast(LinkedList* list, char data);
char deleteFirst(LinkedList* list);
char getFirst(LinkedList* list);
void clearList(LinkedList* list);

#endif
