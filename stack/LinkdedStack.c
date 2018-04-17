#include <stdio.h>
#include <stdlib.h>

// 链栈, 带头结点
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;

// 初始化栈
LNode* initStack()
{
    LNode *list;
    list = (LNode *)malloc(sizeof(LNode));
    list->next = NULL;
    return list;
}

// 判断栈空
int isEmpty(LNode *list)
{
    if (list->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}


// 进栈
void push(LNode *first, int x)
{
    LNode *node;
    node = (LNode *)malloc(sizeof(LNode));
    node->data = x;
    node->next = first->next;
    first->next = node;
}

// 出栈
int pop(LNode *first, int *x)
{
    if (first->next == NULL) {
        return 0;
    }
    
    LNode *node;
    node = first->next;
    *x = node->data;
    first->next = node->next;
    
    free(node);
    
    return 1;
}