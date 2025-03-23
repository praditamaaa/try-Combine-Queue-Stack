/* Queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

typedef struct Queue {
    LinkedList list;
} Queue;

/* Fungsi-fungsi Queue */
void initQueue(Queue* queue);
int isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, char data);
char dequeue(Queue* queue);
char front(Queue* queue);
void clearQueue(Queue* queue);

#endif
