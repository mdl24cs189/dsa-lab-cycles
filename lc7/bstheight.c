#include <stdio.h>
#include <stdlib.h>
#define DATALIMIT 11

int data[DATALIMIT] = { 30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60 };

struct bnode {
	int data;
	struct bnode* left;
	struct bnode* right;
};


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

int findHeight(struct bnode* root) {
    if (root == NULL) return 0;
    return findHeight(root->left) + findHeight(root->right) + 1;
}

int main() {
	struct bnode* root = NULL;
	
	printf("Given data:\n");
	for (int i = 0; i < DATALIMIT; i++) {
		printf("%d ", data[i]);
		root = insertIntoBST(root, data[i]);
	}
    printf("\n");

    printf("Max height of tree: %d\n", findHeight(root));
	return 0;
}