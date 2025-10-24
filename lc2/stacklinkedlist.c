#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = top;
	top = temp;
}

int pop() {
	if (top == NULL) {
		printf("Stack underflow.\n");
		return -1;
	}
	int popValue = top->data;
	struct Node *temp = top;
	top=top->next;
	free(temp);
	return popValue;
}

void displayStack() {
	if (top == NULL) {
		printf("Stack empty.\n");
		return;
	}
	printf("Stack output:\n");
	struct Node *temp = top;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main() {
	int ch = 0;
	while (ch != 4) {
		printf("1. Push\n2. Pop\n3. Display stack\n4. Exit\nEnter a choice (1-4): ");
		scanf("%d", &ch);
		if (ch == 1) {
			printf("Enter value to push: ");
			int value;
			scanf("%d", &value);
			push(value);
		} else if (ch == 2) {
			int popValue = pop();
			if (popValue != -1) {
				printf("Popped value: %d\n", popValue);
			}
		} else if (ch == 3) {
			displayStack();
		} else if (ch == 4) {
			printf("Exiting...\n");
		} else {
			printf("Invalid option!\n");
		}
	}
	return 0;
}
