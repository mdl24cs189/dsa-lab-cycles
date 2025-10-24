#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char elem, char stack[], int* top, int n) {
	if (*(top) + 1 >= n) {
		printf("Stack overflow.\n");
		return;
	}
	*(top) = *(top) + 1;
	stack[*(top)] = elem;
}

char pop(char stack[], int* top) {
	if (*(top) == -1) {
		return '\0';
	}
	char popped = stack[*(top)];
	*(top) = *(top) - 1;
	return popped;
}

void display(char stack[], int top) {
	if (top == -1) {
		printf("None.\n");
		return;
	}
	for (int i = top; i > -1; i--) {
		printf("%d", stack[i]);
	}
	printf("\n");
}

char peek(char stack[], int top) {
	if (top == -1) {
		printf("Stack empty.\n");
		return '\0';
	}
	return stack[top];
}

int main() {
	char STACK[30];
	int top = -1;
	char expr[25];
	printf("Enter a string: ");
	fgets(expr, sizeof(expr), stdin);
	expr[strcspn(expr, "\n")] = 0; // Remove trailing \n
	for (int i = 0; i < strlen(expr); i++) { // Push 0s
		if (expr[i] == '0') {
			push(expr[i], STACK, &top, 30);
		} else if (expr[i] == '1') {
			continue;
		} else {
			printf("Invalid character in string.\n");
			exit(1);
		}
	}
	for (int i = 0; i < strlen(expr); i++) { // Pop 1s
		if (expr[i] == '1') {
			pop(STACK, &top);
		}
	}
	if (top == -1) {
		printf("String has equal 0s and 1s.\n");
	} else {
		printf("String has unequal 0s and 1s.\n");
	}
	return 0;
}
