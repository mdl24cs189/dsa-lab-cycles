#include <stdio.h>
#include <string.h>

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

int main() {
	char STACK[30] = {};
	int top = -1;
	char word[20], reverse[20];
	printf("Enter a word: ");
	fgets(word, sizeof(word), stdin);
	word[strcspn(word, "\n")] = 0; // Remove trailing \n
	for (int i = 0; i < strlen(word); i++) {
		push(word[i], STACK, &top, strlen(word));
	}
	for (int i = 0; i < strlen(word); i++) {
		reverse[i] = pop(STACK, &top);
	}
	reverse[strlen(word)] = '\0';
	printf("Original word: %s\n", word);
	printf("Reversed: %s\n", reverse);
	if (strcmp(word, reverse) == 0) {
		printf("%s is a palindrome.\n", word);
		return 0;
	}
	printf("%s is not a palindrome.\n", word);
	return -1;
}
