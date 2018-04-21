#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}Node;

Node* newNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void insert(Node *root, int data)
{
	Node *current, *prev;
	current = root;
	while (current != NULL) {
		prev = current;
		if (data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	Node *node = newNode(data);
	if (prev->data > data) {
		prev->left = node;
	} else {
		prev->right = node;
	}
}

void inOrder(Node *current)
{
	if (current != NULL) {
		inOrder(current->left);
		printf("%d ", current->data);
		inOrder(current->right);
	}
}

void preOrder(Node *current)
{
	if (current != NULL) {
		printf("%d ", current->data);
		preOrder(current->left);
		preOrder(current->right);
	}
}

void postOrder(Node *current)
{
	if (current != NULL) {
		postOrder(current->left);
		postOrder(current->right);
		printf("%d ", current->data);
	}
}

int main()
{
	Node *root = newNode(50);
	insert(root, 30);
	insert(root, 40);
	insert(root, 100);
	insert(root, 80);
	insert(root, 10);
	insert(root, 90);
	printf("In-order traversal: ");
	inOrder(root);
	printf("\n");
	
	printf("Pre-order traversal: ");
	preOrder(root);
	printf("\n");

	printf("Post-order traversal: ");
	postOrder(root);
	printf("\n");

	return 0;
}