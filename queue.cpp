/* Queue.c */
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue(Queue* queue) {
    initLinkedList(&queue->list);
}

int isQueueEmpty(Queue* queue) {
    return isEmpty(&queue->list);
}

void enqueue(Queue* queue, char data) {
    insertLast(&queue->list, data);
}

char dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue kosong, tidak bisa melakukan dequeue.\n");
        return '\0';
    }
    
    return deleteFirst(&queue->list);
}

char front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return '\0';
    }
    
    return getFirst(&queue->list);
}

void clearQueue(Queue* queue) {
    clearList(&queue->list);
}
