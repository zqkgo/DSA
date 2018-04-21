#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

// 访问结点
void Visit(BTNode *node)
{
    printf("%c ", node->data);
}

// 创建结点
BTNode* newNode(char data)
{
    BTNode *node;
    node = (BTNode *)malloc(sizeof(BTNode));
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}

// 先序遍历
void preOrder(BTNode *node)
{
    if (node != NULL) {
        Visit(node);
        preOrder(node->lchild);
        preOrder(node->rchild);
    }
}

// 中序遍历
void inOrder(BTNode *node)
{
    if (node != NULL) {
        inOrder(node->lchild);
        Visit(node);
        inOrder(node->rchild);
    }
}

// 后序遍历
void postOrder(BTNode *node)
{
    if (node != NULL) {
        postOrder(node->lchild);
        postOrder(node->rchild);
        Visit(node);
    }
}

int main()
{
    BTNode *root = newNode('A');
    root->lchild = newNode('B');
    root->rchild = newNode('C');
    root->lchild->lchild = newNode('D');
    root->lchild->rchild = newNode('E');
    root->rchild->lchild = newNode('F');
    root->rchild->rchild = newNode('G');
    root->lchild->lchild->lchild = newNode('H');
    root->lchild->rchild->lchild = newNode('I');
    root->lchild->rchild->rchild = newNode('J');

    // Visit(root->lchild);
    printf("pre order traversal: \t");
    preOrder(root);
    printf("\n");

    printf("in order traversal: \t");
    inOrder(root);
    printf("\n");

    printf("post order traversal: \t");
    postOrder(root);
    printf("\n");
    
    return 0;
}