#include <stdio.h>

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
		return -1;
	}
	int popped = stack[*(top)];
	*(top) = *(top) - 1;
	return popped;
}

void display(int stack[], int top) {
	if (top == -1) {
		printf("None.\n");
		return;
	}
	for (int i = top; i > -1; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int peek(int stack[], int top) {
	if (top == -1) {
		printf("Stack empty.\n");
		return -1;
	}
	return stack[top];
}

int main() {
	int STACK1[20], STACK2[20];
	int top1 = -1, top2 = -1;
	int min, num;
	printf("Enter number of elements: ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int elem;
		printf("Enter element %d: ", i+1);
		scanf("%d", &elem);
		push(elem, STACK1, &top1, num);
	}
	printf("Elements: ");
	display(STACK1, top1);
	min = pop(STACK1, &top1);
	for (int i = 0; i < num; i++) {
		int popped = pop(STACK1, &top1);
		if (popped < min) {
			push(min, STACK2, &top2, num);
			min = popped;
		}
	}
	printf("Minimum element in stack is: %d\n", peek(STACK2, top2));
	return 0;
}
