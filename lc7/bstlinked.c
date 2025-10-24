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
	temp->next = NULL;
	if (front == NULL) { 
		front = temp;
		rear = temp;
	} else { 
		rear->next = temp;
	}
	rear = temp; 
}

struct bnode* dequeue() {
	if (front == NULL) {
		printf("Queue empty.\n");
		return NULL;
	}
	struct qnode* temp = front;
	struct bnode* treenode = temp->treenode;
	front = temp->next; 
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

void inOrder(struct bnode* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct bnode* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

void preOrder(struct bnode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
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
		
	printf("\nIn order:\n");	
	inOrder(root);
	printf("\nPost order:\n");
	postOrder(root);
	printf("\nPre order:\n");
	preOrder(root);
	printf("\nLevel order:\n");
	levelOrder(root);
	printf("\n");
	return 0;
}