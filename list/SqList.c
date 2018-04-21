#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

// 顺序表的结构体定义
typedef struct {
    int data[maxSize];
    int length;
}SqList;

int insertElem(SqList *L, int p, int e);
int deleteElem(SqList *L, int p, int *e);

int main()
{
    SqList *list;
    list = (SqList *)malloc(sizeof(SqList));
    insertElem(list, 0, 5);
    insertElem(list, 1, 3);
    insertElem(list, 2, 4);
    insertElem(list, 1, 12);
    printf("%d\n", list->length);
    printf("%d\n", list->data[2]);
    int *e = (int *)malloc(sizeof(int));
    deleteElem(list, 0, e);
    printf("%d %d\n", *e, list->data[0]);
    free(list);
    return 0;
}

int insertElem(SqList *L, int p, int e)
{
    int i;
    if (p < 0 || p > L->length || L->length == maxSize)
        return 0;

    // move
    for (i = L->length-1; i >= p; i--) {
        L->data[i+1] = L->data[i];
    }

    L->data[p] = e;
    ++(L->length);
    return 1;
}

int deleteElem(SqList *L, int p, int *e)
{
    int i;
    if (p < 0 || p > L->length) {
        return -1;
    }
    *e = L->data[p];
    // move
    for (i = p; i < L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    --(L->length);
    return 1;
}

