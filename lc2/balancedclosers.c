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
		printf("Stack underflow.\n");
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
	char STACK[30] = {};
	int top = -1;
	char expr[25];
	printf("Enter an expression: ");
	fgets(expr, sizeof(expr), stdin);
	expr[strcspn(expr, "\n")] = 0; // Remove trailing \n
	for (int i = 0; i < strlen(expr); i++) {
		switch (expr[i]) {
			case ')':
				if (peek(STACK, top) == '(') {
					pop(STACK, &top);
				} else {
					printf("Unbalanced.\n");
					exit(0);
				}
				break;
			case '}':
				if (peek(STACK, top) == '{') {
					pop(STACK, &top);
				} else {
					printf("Unbalanced.\n");
					exit(0);
				}
				break;
			case ']':
				if (peek(STACK, top) == '[') {
					pop(STACK, &top);
				} else {
					printf("Unbalanced.\n");
					exit(0);
				}
				break;
			default:
				break;
		}
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
			push(expr[i], STACK, &top, 30);
		}
	}
	if (top == -1) {
		printf("Expression is balanced.\n");
	}
	return 0;
}
