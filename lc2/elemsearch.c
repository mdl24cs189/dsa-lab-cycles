#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void push(int elem, int stack[], int* top, int n) {
	if (*(top) + 1 >= n) {
		printf("Stack overflow.\n");
		return;
	}
	*(top) = *(top) + 1;
	stack[*(top)] = elem;
}

int pop(int stack[], int* top) {
	if (*(top) == -1) {
		printf("Stack underflow.\n");
		return -1;
	}
	int popped = stack[*(top)];
	*(top) = *(top) - 1;
	return popped;
}

void display(int stack[], int top) {
	printf("Stack Output:\n");
	if (top == -1) {
		printf("Stack Empty.\n");
	}
	for (int i = top; i > -1; i--) {
		printf("%d\n", stack[i]);
	}
}

int peek(int stack[], int top) {
	if (top == -1) {
		printf("Stack empty.\n");
		return -1;
	}
	return stack[top];
}

int main() {
	int STACK1[MAX] = {};
	int STACK2[MAX] = {};
	int top1 = -1;
	int top2 = -1;
	int n;
	int search;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int elem;
		printf("Enter element %d: ", i+1);
		scanf("%d", &elem);
		push(elem, STACK1, &top1, n);
	}
	display(STACK1, top1);
	printf("Enter element to search: ");
	scanf("%d", &search);
	int i = 1, flag = 1;
	while(top1 > 0) {
		int popped = pop(STACK1, &top1);
		if (popped == search) {
			printf("Element found at position %d of stack.\n", i);	
			flag = 0;
		}
		push(popped, STACK2, &top2, n);
		i++;
	}
	while (top2 > 0) {
		int popped = pop(STACK2, &top2);
		push(popped, STACK1, &top1, n);
	}
	if (flag == 1) {
		printf("Element not found in stack.\n");
	}
	return 0;
}
