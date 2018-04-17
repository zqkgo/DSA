#include <stdlib.h>
#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;

void createListHead(LNode *list, int a[], int n);
void createListRear(LNode *list, int a[], int n);
int findAndDelete(LNode *list, int data);

int main()
{
    LNode *list1;
    list1 = (LNode *)malloc(sizeof(LNode));
    int a[6] = {2,3,21,66,7,9};
    createListRear(list1, a, 6);
    printf("%d\n", list1->next->next->next->data);
    free(list1);
    
    LNode *list2;
    list2 = (LNode *)malloc(sizeof(LNode));
    int b[4] = {4,5,67,21};
    createListHead(list2, b, 4);
    printf("%d\n", list2->next->next->data);
    
    if (findAndDelete(list2, 67)) {
        printf("%d\n", list2->next->data);
    }

    free(list2);

    return 0;
}

// 头插法
void createListHead(LNode *list, int a[], int n)
{
    // list本身指向头结点
    // 头结点值域不包含信息
    LNode *new;
    list->next = NULL;
    for (int i = 0; i < n; i++) {
        new = (LNode *)malloc(sizeof(LNode));
        new->data = a[i];
        new->next = list->next;
        list->next = new;
    }
}

// 尾插法
void createListRear(LNode *list, int a[], int n)
{
    LNode *new, *end;
    list->next = NULL;
    end = list;
    for (int i = 0; i < n; i++) {
        new = (LNode *)malloc(sizeof(LNode));
        new->data = a[i];
        end->next = new;
        end = end->next;
    }
    end->next = NULL;
}

// 删除结点
int findAndDelete(LNode *list, int data)
{
    LNode *current, *tmp;
    current = list;
    
    while (current->next != NULL) {
        if (current->next->data == data) {
            break;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return 0;
    } else {
        tmp = current->next;
        current->next = tmp->next;
        free(tmp);
        return 1;
    }
}