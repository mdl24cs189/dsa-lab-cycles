#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteSmallest() {
    if (head == NULL) return;
    struct Node* temp = head;
    struct Node* minNode = head;
    while (temp != NULL) {
        if (temp->data < minNode->data) minNode = temp;
        temp = temp->next;
    }
    if (minNode->prev) minNode->prev->next = minNode->next;
    else head = minNode->next;
    if (minNode->next) minNode->next->prev = minNode->prev;
    free(minNode);
}

void display(struct Node* node) {
    struct Node* temp = node;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        append(val);
    }
    deleteSmallest();
    printf("List after deleting smallest: ");
    display(head);
    return 0;
}
