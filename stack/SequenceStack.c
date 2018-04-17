#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

// 顺序栈
typedef struct {
    int data[maxSize];
    int top;
}SqStack;

// 初始化栈
void initStack(SqStack *stack)
{
    stack->top = -1;
}

// 判断栈空
void isEmpty(SqStack *stack)
{
    if (stack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// 进栈
int push(SqStack *stack, int x)
{
    if (stack->top == maxSize-1) {
        return 0;
    }
    ++(stack->top);
    stack->data[stack->top] = x;
    return 1;
}

// 出栈
int pop(SqStack *stack, int *x)
{
    if (stack->top == -1) {
        return 0;
    }
    *x = stack->data[stack->top];
    --(stack->top);
    return 1;
}


