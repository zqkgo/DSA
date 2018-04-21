#include <stdlib.h>
#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;

void createListHead(LNode *list, int a[], int n);
void createListRear(LNode *list, int a[], int n);
int findAndDelete(LNode *list, int data);
void printLinkedList(LNode *node);

int main()
{
    LNode *list1;
    list1 = (LNode *)malloc(sizeof(LNode));
    int a[6] = {2,3,21,66,7,9};
    createListRear(list1, a, 6);
    printf("---------->\n");
    printLinkedList(list1);
    free(list1);
    
    LNode *list2;
    list2 = (LNode *)malloc(sizeof(LNode));
    int b[4] = {4,5,67,21};
    createListHead(list2, b, 4);
    printf("<---------\n");
    printLinkedList(list2);
    
    if (findAndDelete(list2, 67)) {
        printf("%d\n", list2->next->data);
    }

    free(list2);

    return 0;
}

// 头插法
void createListHead(LNode *head, int a[], int n)
{
    // head本身指向头结点
    // 头结点值域不包含信息
    LNode *new;
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        new = (LNode *)malloc(sizeof(LNode));
        new->data = a[i];
        new->next = head->next;
        head->next = new;
    }
}

// 尾插法
void createListRear(LNode *head, int a[], int n)
{
    LNode *new, *end;
    head->next = NULL;
    end = head;
    for (int i = 0; i < n; i++) {
        new = (LNode *)malloc(sizeof(LNode));
        new->data = a[i];
        end->next = new;
        end = end->next;
    }
    end->next = NULL;
}

// 删除结点
int findAndDelete(LNode *head, int data)
{
    LNode *current;
    current = head;
    
    while (current->next != NULL) {
        if (current->next->data == data) {
            break;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return 0;
    } else {
        LNode *tmp;
        tmp = current->next;
        current->next = tmp->next;
        free(tmp);
        return 1;
    }
}

void printLinkedList(LNode *head)
{
    LNode *current;
    current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}