#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int QUEUE[MAX];
int front = 0, rear = 0;

int isEmpty() {
	if (rear==front) {
		return 1;
	}
	return 0;
}

int isFull() {
	if ((rear+1) % MAX == front) {
		return 1;
	}
	return 0;
}

void enqueue(int x) {
	if (isFull()) {
		printf("Queue overflow.\n");
		return;
	}
	rear = (rear + 1) % MAX;
	QUEUE[rear] = x;
}

int dequeue() {
	if (isEmpty()) {
		printf("Queue underflow.\n");
		front = 0; // Reset queue
		rear = 0;
		return -1;
	}
	int dequeued = QUEUE[front];
	front = (front + 1) % MAX;
	printf("Dequeued element: %d\n", dequeued);
	return dequeued;
}

int peek() {
	if (front == rear) {
		printf("Queue empty.\n");
		return -1;
	}
	printf("Peeked: %d\n", QUEUE[(front + 1) % MAX]);
	return QUEUE[(front + 1) % MAX];
}

void display() {
	if (isEmpty()) {
		printf("Queue empty.\n");
		return;
	}
	int i = (front + 1) % MAX;
	printf("Queue:\n");
	while (i != (rear + 1) % MAX) {
		printf("%d\n", QUEUE[i]);
		i = (i+1) % MAX;
	}
}

int main() {
	int ch;
	int x;
	while (0 < 1) {
		printf("\n\nQueue Menu: (Choices 1-5)\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
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
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
	return 0;
}
