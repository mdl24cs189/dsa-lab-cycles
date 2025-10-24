#include <stdio.h>

void push1(int elem, int stack[], int* top1, int *top2, int n) {
	if (*(top1) + 1 >= *(top2)) {
		printf("Stack overflow.\n");
		return;
	}
	*(top1) = *(top1) + 1;
	stack[*(top1)] = elem;
	printf("%d pushed.\n", stack[*(top1)]);
}

void push2(int elem, int stack[], int* top1, int *top2, int n) {
	if (*(top1) + 1 >= *(top2)) {
		printf("Stack overflow.\n");
		return;
	}
	*(top2) = *(top2) - 1;
	stack[*(top2)] = elem;
	printf("%d pushed.\n", stack[*(top2)]);
}

void pop1(int stack[], int* top1) {
	if (*(top1) == -1) {
		printf("Stack underflow.\n");
		return;
	}
	printf("%d popped.\n", stack[*(top1)]);
	stack[*(top1)] = NULL;
	*(top1) = *(top1) - 1;
}

void pop2(int stack[], int* top2, int n) {
	if (*(top2) >= n) {
		printf("Stack underflow.\n");
		return;
	}
	printf("%d popped.\n", stack[*(top2)]);
	stack[*(top2)] = NULL;
	*(top2) = *(top2) + 1;
}

void displayStack(int stack[], int top1, int top2, int n) {
	if (top1 == -1 && top2 >= n) {
		printf("Stack empty.\n");
		return;
	}
	printf("Stack Output:\n");
	if (top2 < n) {
		for (int i = top2; i < n; i++) {
			printf("%d]", stack[i]);
		}
	}
	if (top1 != -1) {
		for (int i = top1; i > -1; i--) {
			printf("[%d", stack[i]);
		}
	}
	printf("\n");
}

int main() {
	int STACK[10] = {};
	int top1 = -1;
	int top2 = 10;
	push1(10, STACK, &top1, &top2, 10);
	push1(20, STACK, &top1, &top2, 10);
	push1(60, STACK, &top1, &top2, 10);
	push2(70, STACK, &top1, &top2, 10);
	push2(80, STACK, &top1, &top2, 10);
	push2(90, STACK, &top1, &top2, 10);
	displayStack(STACK, top1, top2, 10);
	pop1(STACK, &top1);
	pop2(STACK, &top2, 10);
	displayStack(STACK, top1, top2, 10);
	return 0;
}
