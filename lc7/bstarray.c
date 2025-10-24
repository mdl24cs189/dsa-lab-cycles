#include <stdio.h>
#define MAX 16
#define DATALIMIT 11

int	BST[MAX];
int data[DATALIMIT] = { 30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60 };

void initialise_tree() {
	for (int i = 0; i < MAX; i++) {
		BST[i] = -1;
	}
}

void insert_in_tree(int elem) {
	int i = 0;
	while (i < MAX) {
		if (BST[i] == -1) {
			BST[i] = elem;
			return;
		}
		
		if (BST[i] < elem) {
			i = 2*i + 2; 
		} else if (BST[i] > elem) {
			i = 2*i + 1;
		} else {
			return; // Duplicate element
		}
	}
}

void display_binary_tree() {
	for (int i = 0; i < MAX; i++) {
		printf("%d ", i);
		if (BST[i] == -1) {
			printf("-");
		} else {
			printf("%d", BST[i]);
		}
		printf("\n");
	}
}

int main() {
	initialise_tree();
	for (int i = 0; i < DATALIMIT; i++) {
		insert_in_tree(data[i]);
	}
	printf("Array representation:\n");
	display_binary_tree();
	return 0;
}