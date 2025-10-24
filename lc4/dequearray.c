#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int DEQUE[MAX];
int front = -1; 
int rear = -1;

int is_full() {
	if ((rear + 1) % MAX == front) {
		return 1;
	}
	return 0;
}

int is_empty() {
	if (front == -1 && rear == -1) {
		return 1;
	}
	return 0;
}

void insert_front(int x) {
	if (is_full()) {
		printf("Deque Overflow.\n");
		return;
	}
	if (is_empty()) {
		front = 0;
		rear = 0;
	} else {
		front = (front - 1 + MAX) % MAX;
	}
	DEQUE[front] = x;
}

void insert_rear(int x) {
	if (is_full()) {
		printf("Deque Overflow.\n");
		return;
	} else if (is_empty()) {
		front = 0;
		rear = 0;
	} else {
		rear = (rear + 1) % MAX;
	}
	DEQUE[rear] = x;
}

int delete_front() {
	if (is_empty()) {
		printf("Deque Underflow.\n");
		return -1;
	}
	int removed = DEQUE[front];
	if (front == rear) {
		front = rear = -1;
		return removed;
	} 
	front = (front + 1) % MAX;
	return removed;
}

int delete_rear() {
	if (is_empty()) {
		printf("Deque Underflow.\n");
		return -1;
	}
	int removed = DEQUE[rear];
	if (front == rear) {
		front = rear = -1;
	} else {
		rear = (rear - 1 + MAX) % MAX;
	}
	return removed;
}

int peek_front() {
	if (is_empty()) {
		printf("Deque Empty.\n");
		return -1;
	}
	return DEQUE[front];
}

int peek_rear() {
	if (is_empty()) {
		printf("Deque Empty.\n");
		return -1;
	}
	return DEQUE[rear];
}

void display() {
	if (is_empty()) {
		printf("Deque Empty.\n");
		return;
	}
	int i = front;
	do {
		printf("%d ", DEQUE[i]);
		i = (i + 1) % MAX;
	} while (i != (rear + 1) % MAX);
}

int main() {
	int ch;
	int x;
	int checked;
	while (0 < 1) {
		printf("\n\nDeque Menu: (Choices 1-8)\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n");
		printf("4. Delete Rear\n5. Peek Front\n6. Peek Rear\n7. Display\n8. Exit\n");
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
				checked = peek_front();
				if (checked != -1) {
					printf("Peeked front: %d\n", checked); 
				}
				break;
			case 6:
				checked = peek_rear();
				if (checked != -1) {
					printf("Peeked rear: %d\n", checked);
				}
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
	return 0;
}
