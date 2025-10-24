#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int QUEUE[MAX];
int STACK[MAX];
int front = -1, rear = -1;
int top = -1;

void enqueue(int x) {
	if (rear == MAX-1) {
		printf("Stack overflow.\n");
		return;
	}
	rear++;
	QUEUE[rear] = x;
}

int dequeue() {
	if (front == rear) {
		printf("Stack underflow.\n");
		front = -1; // Reset queue
		rear = -1;
		return -1;
	}
	return QUEUE[++front];
}

void display() {
    if (front == rear) {
        printf("Queue empty.\n");
        return;
    }
    int i = front + 1;
    printf("Queue:\n");
    while (i <= rear) { 
        printf("%d\n", QUEUE[i]);
        i++;
    }
}

void push(int elem, int n) {
	if (top + 1 >= n) {
		printf("Stack overflow.\n");
		return;
	}
	top++;
	STACK[top] = elem;
	printf("%d pushed.\n", STACK[top]);
}

void displayStack() {
	printf("Reversed Output:\n");
	if (top == -1) {
		printf("None.\n");
	}
	for (int i = top; i > -1; i--) {
		printf("%d\n", STACK[i]);
	}
}

int main() {
	int ch;
	int x;
	int dequeued;
	while (1) {
		printf("\n\nQueue Menu: (Choices 1-4)\n1. Enqueue\n2. Reverse Queue\n3. Display Queue\n4. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:	
				printf("Enter element to enqueue: ");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2:
				while (front != rear) {
					dequeued = dequeue();
					if (dequeued != -1) {
						push(dequeued, MAX);
					}
				}
				displayStack();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}	
	return 0;
}
