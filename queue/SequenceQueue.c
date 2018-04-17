#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

// 循环队列
typedef struct
{
    int data[maxSize];
    int front;
    int rear;
}SequenceQueue;

SequenceQueue* initQueue()
{
    SequenceQueue *queue;
    queue = (SequenceQueue *)malloc(sizeof(SequenceQueue));
    queue->front = queue->rear = 0;
    return queue;
}

// 队空
int isEmpty(SequenceQueue *queue)
{
    if (queue->front == queue->rear) {
        return 1;
    } else {
        return 0;
    }
}

// 队满
int isFull(SequenceQueue *queue)
{
    if ((queue->rear + 1) % maxSize == queue->front) {
        return 1;
    } else {
        return 0;
    }
}

// 进队
int enQueue(SequenceQueue *queue, int x)
{
    if (isFull(queue)) {
        return 0;
    }

    queue->rear = (queue->rear + 1) % maxSize;
    queue->data[queue->rear] = x;
    return 1;
}

// 出队
int deQueue(SequenceQueue *queue, int *x)
{
    if (isEmpty(queue)) {
        return 0;
    }
    queue->front = (queue->front + 1) % maxSize;
    *x = queue->data[queue->front];
    return 1;
}