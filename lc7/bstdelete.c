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

int deleteElement(struct bnode* root, int data) {
    struct bnode* current = root;
    while (current != NULL) {
        if (data == current->data) {
            int tempData = current->data;
            free(current); // Free node from tree
            return tempData;
        } else if (data < current->data) {
            printf("Going left %d>%d\n", current->data, data);
            current = current->left;
        } else {
            printf("Going right %d<%d\n", current->data, data);
            current = current->right;
        }
    }
    return 0; // Node not found     
}

int main() {
	struct bnode* root = NULL;
	
	printf("Given data:\n");
	for (int i = 0; i < DATALIMIT; i++) {
		printf("%d ", data[i]);
		root = insertIntoBST(root, data[i]);
	}
    printf("\n");

    printf("Enter node to delete: ");
    int target;
    scanf("%d", &target);
    if (deleteElement(root, target)) {
        printf("Node %d found in the BST and removed.\n", target);
    } else {
        printf("Node %d not found in the BST and not removed.\n", target);
    }

	return 0;
}