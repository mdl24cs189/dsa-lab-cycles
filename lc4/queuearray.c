#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int QUEUE[MAX];
int front = -1, rear = -1;

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

int peek() {
	if (front == rear) {
		printf("Queue empty.\n");
		return -1;
	}
	return QUEUE[front+1];
}

void display() {
	if (front == rear) {
		printf("Queue empty.\n");	
	}
	int i = front + 1;
	printf("Queue:\n");
	while (i <= rear) {
		printf("%d\n", QUEUE[i]);
		i++;
	}
	return;
}

int main() {
	int ch;
	int x;
	while (0 < 1) {
		printf("\n\nQueue Menu: (Choices 1-5)\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:	
				printf("Enter element to enqueue: ");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2:
				dequeue();
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
	return 0;
}
