#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
char stack[MAX];
int top = -1;

void push(char elem) {
	if (top + 1 >= MAX) {
		printf("Stack overflow.\n");
		return;
	}
	top = top + 1;
	stack[top] = elem;
}

char pop() {
	if (top == -1) {
		return '\0';
	}
	char popped = stack[top];
	top -= 1;
	return popped;
}

char peek() {
	if (top == -1) {
		printf("Stack empty.\n");
		return '\0';
	}
	return stack[top];
}

int exponent(int val, int exp) {
	int result = 1;
	for (int i = 1; i < exp + 1; i++) {
		result *= val;
	}
	return result;
}

int evaluatePostfix(char postfix[]) {
	char c;
	int val;
	
	for (int i = 0; postfix[i] != '\0'; i++) {
		c = postfix[i];
		
		if (isdigit(c)) {
			push(c - '0');
		} else if (c == ' ') {
			continue;
		} else {
			int v2 = pop();
			int v1 = pop();
			
			switch(c) {
				case '+':
					push(v1 + v2);
					break;
				case '-':
					push(v1 - v2);
					break;
				case '*':
					push(v1*v2);
					break;
				case '/':
					push(v1/v2);
					break;
				case '^':
					push(exponent(v1, v2));
					break;
				default:
					printf("Unknown operator.\n");
					exit(1);
					break;
			}
		}
	}
	
	return pop();
}

int main() {
	char STACK[MAX] = {};
	int top = -1;
	char expr[MAX];
	printf("Enter postfix: ");
	fgets(expr, sizeof(expr), stdin);
	expr[strcspn(expr, "\n")] = 0; // Remove trailing \n
	int result = evaluatePostfix(expr);
	printf("Evaluated value: %d\n", result);
	return 0;
}
