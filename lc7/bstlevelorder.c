#include <stdio.h>
#include <stdlib.h>
#define DATALIMIT 11

int data[DATALIMIT] = { 30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60 };

struct bnode {
	int data;
	struct bnode* left;
	struct bnode* right;
};

struct qnode {
	struct bnode* treenode;
	struct qnode* next;
};
struct qnode *front = NULL;
struct qnode *rear = NULL;


void enqueue(struct bnode* treenode) {
	struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
	temp->treenode = treenode;
	if (front == NULL) {
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

struct bnode* dequeue() {
	if (front == NULL) {
		printf("Queue empty.\n");
		return NULL;
	}
	struct qnode* temp = front;
	struct bnode* treenode = front->treenode;
	front=front->next;
	if (front == NULL) {
		rear = NULL;
	}
	free(temp);
	return treenode;
}

int isQueueEmpty() {
	return (front == NULL);
}

struct bnode* createNewbnode(int data) {
	struct bnode* temp = (struct bnode*)malloc(sizeof(struct bnode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct bnode* insertIntoBST(struct bnode* root, int data) {
	if (root == NULL) {
		return createNewbnode(data);
	}
	if (data < root->data) {
		root->left = insertIntoBST(root->left, data);
	} else {
		root->right = insertIntoBST(root->right, data);
	}
	
	return root;
}

void levelOrder(struct bnode* root) {
	if (root != NULL) {
		enqueue(root);
	}
	
	while (!isQueueEmpty()) {
		struct bnode *current = dequeue();
		printf("%d ", current->data);
		if (current->left != NULL) {
			enqueue(current->left);
		}
		if (current->right != NULL) {
			enqueue(current->right);
		}
	}
}

int main() {
	struct bnode* root = NULL;
	
	printf("Given data:\n");
	for (int i = 0; i < DATALIMIT; i++) {
		printf("%d ", data[i]);
		root = insertIntoBST(root, data[i]);
	}
	
	printf("\nLevel order:\n");
	levelOrder(root);
	printf("\n");
	return 0;
}