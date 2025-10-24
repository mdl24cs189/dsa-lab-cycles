#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	if (front == NULL) {
		front = rear = temp;
		rear->next = front;
		return;
	}
	rear->next = temp;
	rear = temp;
	rear->next = front;
}

int dequeue() {
	if (front == NULL) {
		printf("Queue empty.\n");
		return -1;
	}
	struct node* temp = front;
	int dequeued = front->data;
	if (front == rear) {
		front = NULL;
		rear = NULL;
	} else {
		front = front->next;
		rear->next = front;
	}
	free(temp);
	return dequeued;
}

void display() {
	if (front == NULL) {
		printf("Queue empty.\n");
		return;
	}
	printf("Queue content:\n");
	struct node* temp = front;
	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != front);
	printf("\n");
}

int main() {
	int ch;
	int x;
	while (0 < 1) {
		printf("\n\nCircular Queue Menu: (Choices 1-5)\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
				exit(1);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
	return 0;
}
