#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

void createListRear(DLNode *node, int a[], int n);
DLNode* findNode(DLNode *node, int a);
void insertNode(DLNode *node, int a, int b);
void deleteNode(DLNode *node, int a);

int main()
{
    int a[5] = {1,76,34,2,100};
    DLNode *head;
    head = (DLNode *)malloc(sizeof(DLNode));
    createListRear(head, a, 5);
    printf("%d\n", head->next->next->next->prior->data); // 76

    // print all address
    DLNode *current;
    current = head->next;
    while (current != NULL) {
        printf("%d -> %p\n", current->data, current);
        current = current->next;
    }
    current = findNode(head, 34);
    if (current != NULL) {
        printf("%d -> %p\n", current->data, current);
    }

    deleteNode(head, 2);
    printf("%d \n", head->next->next->next->next->data); // 100
    printf("%d \n", head->next->next->next->next->prior->data); // 34

    return 0;
}

// 尾插法
void createListRear(DLNode *node, int a[], int n)
{
    DLNode *new, *end;
    node->prior = NULL;
    node->next = NULL;
    end = node;
    for (int i; i < n; i++) {
        new = (DLNode *)malloc(sizeof(DLNode));
        new->data = a[i];
        end->next = new;
        new->prior = end;
        end = new;
    }
    end->next = NULL;
}

// 查找结点
DLNode* findNode(DLNode *node, int a)
{
    DLNode *p = node->next;
    while (p != NULL) {
        if (p->data == a) {
            break;
        }
        p = p->next;
    }
    return p;
}

// 插入结点
void insertNode(DLNode *node, int a, int b) 
{
    DLNode *before, *after;
    before = findNode(node, a);
    after->data = b;
    after->next = before->next;
    after->prior = before;
    before->next = after;
    after->next->prior = after;
}

// 删除结点
void deleteNode(DLNode *node, int a)
{
    DLNode *deleted, *prior;
    deleted = findNode(node, a);
    prior = deleted->prior;
    prior->next = deleted->next;
    prior->next->prior = prior;
    free(deleted);
}