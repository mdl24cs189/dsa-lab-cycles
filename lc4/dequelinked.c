#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};
struct node *front = NULL;
struct node *rear = NULL;

void insert_front(int x) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = front;
	if (front == NULL) {
		rear = temp;
	} else {
		front->prev = temp;
	}
	front = temp;
}

void insert_rear(int x) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->prev = rear;
	temp->next = NULL;
	if (rear == NULL) {
		front = temp;
	} else {
		rear->next = temp;
	}
	rear = temp;
}

int delete_front() {
	if (front == NULL) {
		printf("Deque is empty.\n");
		return -1;
	}
	struct node* temp = front;
	int deleted = temp->data;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	} else {
		front->prev = NULL;
	}
	free(temp);
	return deleted;
}

int delete_rear() {
	if (rear == NULL) {
		printf("Deque is empty.\n");
		return -1;
	}
	struct node* temp = rear;
	int deleted = temp->data;
	rear = rear->prev;
	if (rear == NULL) {
		front = NULL;
	} else {
		rear->next = NULL;
	}
	free(temp);
	return deleted;
}

void display() {
	if (front == NULL) {
		printf("Deque empty.\n");
		return;
	}
	printf("Deque content:\n");
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
	int checked;
	while (0 < 1) {
		printf("\n\nDeque Menu: (Choices 1-6)\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n");
		printf("4. Delete Rear\n5. Display\n6. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				printf("Enter element to insert: ");
				scanf("%d", &x);
				insert_front(x);
				break;
			case 2:
				printf("Enter element to insert: ");
				scanf("%d", &x);
				insert_rear(x);
				break;
			case 3:
				checked = delete_front();
				if (checked != -1) {
					printf("Deleted front: %d\n", checked); 
				}
				break;
			case 4:
				checked = delete_rear();
				if (checked != -1) {
					printf("Deleted rear: %d\n", checked);
				}
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
	return 0;
}
