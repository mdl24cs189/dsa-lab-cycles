#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct Node {
    int data;
    int priority;
};
struct Node* QUEUE[MAX];
int size = 0;

struct Node* createNewNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && QUEUE[left] && QUEUE[left]->priority > QUEUE[largest]->priority)
        largest = left;
    if (right < size && QUEUE[right] && QUEUE[right]->priority > QUEUE[largest]->priority)
        largest = right;

    if (largest != i) {
        struct Node* temp = QUEUE[i];
        QUEUE[i] = QUEUE[largest];
        QUEUE[largest] = temp;
        maxHeapify(largest);
    }
}

void buildMaxHeap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(i);
    }
}

void insert(int data, int priority) {
    struct Node* newNode = createNewNode(data, priority);
    QUEUE[size] = newNode;
    int current = size;
    size++;

    while (current > 0 && QUEUE[(current - 1) / 2]->priority < QUEUE[current]->priority) {
        struct Node* temp = QUEUE[current];
        QUEUE[current] = QUEUE[(current - 1) / 2];
        QUEUE[(current - 1) / 2] = temp;
        current = (current - 1) / 2;
    }
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", QUEUE[i]->data, QUEUE[i]->priority);
    }
    printf("\n");
}

int main() {
    int ch, data, priority;
    while (1) {
        printf("1. Insert node\n2. Display heap\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(data, priority);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}