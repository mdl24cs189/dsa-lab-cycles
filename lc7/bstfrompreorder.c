#include <stdio.h>
#include <stdlib.h>

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
        root = createNewbnode(data);
        return root;
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

int main() {
    printf("Enter number of nodes: ");
    int n;
    scanf("%d", &n);
    struct bnode* root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter node %d of preorder: ", i + 1);
        scanf("%d", &data);
        root = insertIntoBST(root, data);
    }
    printf("\nInorder traversal:\n");
    inOrder(root);
    printf("\nPostorder traversal:\n");
    postOrder(root);
    printf("\n");
    return 0;
}