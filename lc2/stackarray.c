#include <stdio.h>

void push(int elem, int stack[], int* top, int n) {
	if (*(top) + 1 >= n) {
		printf("Stack overflow.\n");
		return;
	}
	*(top) = *(top) + 1;
	stack[*(top)] = elem;
	printf("%d pushed.\n", stack[*(top)]);
}

void pop(int stack[], int* top) {
	if (*(top) == -1) {
		printf("Stack underflow.\n");
		return;
	}
	printf("%d popped.\n", stack[*(top)]);
	stack[*(top)] = NULL;
	*(top) = *(top) - 1;
}

void display(int stack[], int top) {
	printf("Stack Output:\n");
	if (top == -1) {
		printf("None.\n");
	}
	for (int i = top; i > -1; i--) {
		printf("%d\n", stack[i]);
	}
}

int main() {
	int STACK[5] = {};
	int top = -1;
	push(30, STACK, &top, 5);
	push(40, STACK, &top, 5);
	push(50, STACK, &top, 5);
	push(60, STACK, &top, 5);
	push(70, STACK, &top, 5);
	display(STACK, top);
	pop(STACK, &top);
	display(STACK, top);
	return 0;
}
