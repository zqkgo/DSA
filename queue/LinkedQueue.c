#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

// 队结点
typedef struct QueueNode 
{
    int data;
    struct QueueNode *next;
}QueueNode;

// 链队
typedef struct
{
    QueueNode *front;
    QueueNode *rear;
}LinkedQueue;

LinkedQueue* initQueue()
{
    LinkedQueue *queue;
    queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    queue->front = queue->rear = NULL;
}

int isEmpty(LinkedQueue *queue)
{
    if (queue->front == NULL || queue->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(LinkedQueue *queue, int x)
{
    QueueNode *node;
    node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = x;
    node->next = NULL;
    if (isEmpty(queue)) { // 队列为空
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int deQueue(LinkedQueue *queue, int *x)
{
    QueueNode *node;
    if (isEmpty(queue)) {
        return 0;
    } else {
        node = queue->front;
    }
    if (queue->front == queue->rear) { // 只有一个结点
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    *x = node->data;
    free(node);
    return 1;
}

void printQueue(LinkedQueue *queue)
{
    if (!isEmpty(queue)) {
        QueueNode *current;
        current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

int main()
{
    LinkedQueue *queue;
    queue = initQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    printQueue(queue);
    return 0;
}
