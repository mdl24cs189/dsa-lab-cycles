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

int findMaxElement(struct bnode* root) {
    if (root == NULL) return -1;
    struct bnode* current = root;

    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int findMinElement(struct bnode* root) {
    if (root == NULL) return -1;
    struct bnode* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

int main() {
	struct bnode* root = NULL;
	
	printf("Given data:\n");
	for (int i = 0; i < DATALIMIT; i++) {
		printf("%d ", data[i]);
		root = insertIntoBST(root, data[i]);
	}
    printf("\n");

    printf("Max element of BST: %d\n", findMaxElement(root));
    printf("Min element of BST: %d\n", findMinElement(root));

	return 0;
}