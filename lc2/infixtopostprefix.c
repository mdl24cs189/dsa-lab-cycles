#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
char stack[MAX];
int top = -1;

void resetStack() {
	top = -1;
}

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

char peek() {
	if (top == -1) {
		printf("Stack empty.\n");
		return '\0';
	}
	return stack[top];
}

void reverseString(char* str) {
    if (str == NULL) {
    	return;
    }
    int length = strlen(str);
    char temp;
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int precedence(char c) {
	if (c == '^') {
		return 3;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}

void swapParantheses(char* str) {
	if (str == NULL) {
		return;
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			str[i] == ')';
		} else if (str[i] == ')') {
			str[i] == '(';
		}
	}
}

char* infixToPostfix(char infix[]) {
	char* postfix = (char*)malloc(strlen(infix) + 1);
	int i, j = 0;
	char c;
	
	resetStack();
	
	for (i = 0; infix[i] != '\0'; i++) {
		c = infix[i];
		
		if (isalpha(c) || isdigit(c)) { // Alphabet or Digit
			postfix[j++] = c;
		} else if (c == '(') { // Bracket start
			push(c);
		} else if (c == ')') { // Bracket close
			while (top != -1 && peek() != '(') {
				postfix[j++] = pop();
			}
			pop();
		} else { // Operator evaluation
			while (top != -1 && precedence(peek()) >= precedence(c)) {
				postfix[j++] = pop();
			}
			push(c);
		}
	}
	
	while (top != -1) {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	
	return postfix;
}

char* infixToPrefix(char infix[]) {
	char* tempInfix = (char*)malloc(strlen(infix) + 1);
	strcpy(tempInfix, infix);
	reverseString(tempInfix);
	swapParantheses(tempInfix);
	
	char* tempPostfix = infixToPostfix(tempInfix);
	free(tempInfix);
	reverseString(tempPostfix);
	return tempPostfix;
}

int main() {
	char STACK[MAX] = {};
	int top = -1;
	char expr[MAX];
	char* postfix = NULL;
	char* prefix = NULL;
	
	printf("Enter infix: ");
	fgets(expr, sizeof(expr), stdin);
	expr[strcspn(expr, "\n")] = '\0';
	
	postfix = infixToPostfix(expr);
	prefix = infixToPrefix(expr);
	printf("Postfix expression: %s\n", postfix);
	printf("Prefix expression: %s\n", prefix);
	return 0;
}
