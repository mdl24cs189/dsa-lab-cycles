#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int priority;
	struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x, int pr) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->priority = pr;
	if (front == NULL || pr > front->priority) {
		temp->next = front;
		front = temp;
		return;
	}
	struct node* current = front;
	while (current->next != NULL && current->next->priority >= pr) {
		current = current->next;
	}
	temp->next = current->next;
	current->next = temp;
}

int dequeue() {
	if (front == NULL) {
		printf("Queue empty.\n");
		return -1;
	}
	struct node* temp = front;
	int dequeued = front->data;
	front=front->next;
	if (front == NULL) {
		rear = NULL;
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
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main() {
	int ch;
	int x;
	int y;
	while (0 < 1) {
		printf("\n\nQueue Menu: (Choices 1-4)\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:	
				printf("Enter element to enqueue: ");
				scanf("%d", &x);
				printf("Enter priority: ");
				scanf("%d", &y);
				enqueue(x, y);
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
}
