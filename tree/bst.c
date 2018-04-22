#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int key;
	int val;
	int N;
	struct Node *left;
	struct Node *right;
}Node;

int size(Node *node)
{
	if (node == NULL) {
		return 0;
	} else {
		return node->N;
	}
}

Node* newNode(int key, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->key = key;
	node->val = val;
	node->N = 1;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node *node, int key, int val)
{
	if (node == NULL) {
		return newNode(key, val);
	}
	if (key < node->key) {
		node->left = insert(node->left, key, val);
	} else if (key > node->key) {
		node->right = insert(node->right, key, val);
	} else {
		node->val = val;
	}
	node->N = size(node->left) + size(node->right) + 1;
	return node;
}

void inOrder(Node *current)
{
	if (current != NULL) {
		inOrder(current->left);
		printf("key: %d , val: %d, child-nodes: %d\n", current->key, current->val, current->N);
		inOrder(current->right);
	}
}

void preOrder(Node *current)
{
	if (current != NULL) {
		printf("key: %d , val: %d, child-nodes: %d\n", current->key, current->val, current->N);
		preOrder(current->left);
		preOrder(current->right);
	}
}

void postOrder(Node *current)
{
	if (current != NULL) {
		postOrder(current->left);
		postOrder(current->right);
		printf("key: %d , val: %d, child-nodes: %d\n", current->key, current->val, current->N);
	}
}

int main()
{
	Node *root = newNode(50, 100);
	insert(root, 30, 678);
	insert(root, 60, 54);
	insert(root, 25, 67);
	insert(root, 35, 90);
	insert(root, 55, 12);
	insert(root, 70, 45);
	insert(root, 20, 12);
	printf("In-order traversal: \n");
	inOrder(root);
	printf("\n");
	
	printf("Pre-order traversal: \n");
	preOrder(root);
	printf("\n");

	printf("Post-order traversal: \n");
	postOrder(root);
	printf("\n");

	return 0;
}