#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// 顺序栈
typedef struct {
    int data[MAXSIZE];
    int top;
}SqStack;

// 初始化栈
SqStack* initStack()
{
    SqStack *stack;
    stack = (SqStack *)malloc(sizeof(SqStack));
    stack->top = -1; // important
    return stack;
}

// 判断栈空
int isEmpty(SqStack *stack)
{
    if (stack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// 判断栈满
int isFull(SqStack *stack)
{
    if (stack->top == MAXSIZE - 1) {
        return 1;
    } else {
        return 0;
    }
} 

// 进栈
int push(SqStack *stack, int x)
{
    if (isFull(stack)) {
        return 0;
    }
    ++(stack->top);
    stack->data[stack->top] = x;
    return 1;
}

// 出栈
int pop(SqStack *stack, int *x)
{
    if (isEmpty(stack)) {
        return 0;
    }
    *x = stack->data[stack->top];
    --(stack->top);
    return 1;
}

void pushArrToStack(SqStack *stack, int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
}

void popArrFromStack(SqStack *stack)
{
    int *data;
    data = (int *)malloc(sizeof(int));
    while (pop(stack, data)) {
        printf("%d ", *data);
    }
    printf("\n");
}

int main()
{
    SqStack *stack = initStack();
    int arr[5] = {1,2,3,4,5};

    pushArrToStack(stack, arr, 5);
    
    popArrFromStack(stack);
    
    return 0;
}


