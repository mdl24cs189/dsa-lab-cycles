#include <stdio.h>

void push(int elem, int stack[], int* top, int n) {
	if (*(top) + 1 >= n) {
		printf("Stack overflow.\n");
		return;
	}
	*(top) = *(top) + 1;
	stack[*(top)] = elem;
}

void pop(int stack[], int* top) {
	if (*(top) == -1) {
		printf("Stack underflow.\n");
		return;
	}
	stack[*(top)] = NULL;
	*(top) = *(top) - 1;
}

void display(int stack[], int top) {
	if (top == -1) {
		printf("None.\n");
		return;
	}
	for (int i = top; i > -1; i--) {
		printf("%d", stack[i]);
	}
	printf("\n");
}

int main() {
	int STACK[30] = {};
	int top = -1;
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("%d in binary is ", num);
	while (num > 1) {
		push(num % 2, STACK, &top, 30);
		num = num / 2;
	}
	push(1, STACK, &top, 30);
	display(STACK, top);
	return 0;
}
