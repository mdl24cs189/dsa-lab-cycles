#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int QUEUE1[MAX];
int QUEUE2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int x) {
	if (rear1 == MAX-1) {
		printf("Queue overflow.\n");
		return;
	}
	rear1++;
	QUEUE1[rear1] = x;
}

int dequeue1() {
	if (front1 == rear1) {
		printf("Queue underflow.\n");
		front1 = -1; // Reset queue
		rear1 = -1;
		return -1;
	}
	return QUEUE1[++front1];
}

void enqueue2(int x) {
	if (rear2 == MAX-1) {
		printf("Queue overflow.\n");
		return;
	}
	rear2++;
	QUEUE2[rear2] = x;
}

int dequeue2() {
	if (front2 == rear2) {
		printf("Queue underflow.\n");
		front2 = -1; // Reset queue
		rear2 = -1;
		return -1;
	}
	return QUEUE2[++front2];
}

void display1() {
	if (front1 == rear1) {
		printf("Queue empty.\n");	
	}
	int i = front1 + 1;
	printf("Queue:\n");
	while (i <= rear1) {
		printf("%d\n", QUEUE1[i]);
		i++;
	}
	return;
}

void push(int x) {
    if (rear1 == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    
    enqueue2(x);
    
    while (front1 != rear1) {
        int temp = dequeue1();
        if (temp != -1) {
            enqueue2(temp);
        }
    }
    
    while (front2 != rear2) {
        int temp = dequeue2();
        if (temp != -1) {
            enqueue1(temp);
        }
    }
}

int pop() {
    return dequeue1();
}

int main() {
	int ch, x, popped;
	while (0 < 1) {
		printf("\n\nQueue Menu: (Choices 1-5)\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:	
				printf("Enter element to enqueue: ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				popped = pop();
				if (popped != -1) {
					printf("Popped element: %d\n", popped);
				}
				break;
			case 3:
				display1();
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
