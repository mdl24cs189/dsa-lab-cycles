#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(Node** head, Node* node, int data) {
    Node* newNode = createNode(data);
    newNode->next = node;
    newNode->prev = node->prev;
    if (node->prev) {
        node->prev->next = newNode;
    } else {
        *head = newNode;
    }
    node->prev = newNode;
}

void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int data1, data2;
    Node* head = NULL;
    printf("Enter data for node 1: ");
    scanf("%d", &data1);
    head = createNode(data1);
    printf("Enter data for new node to insert in front of node 1: ");
    scanf("%d", &data2);
    insertBefore(&head, head, data2);
    printf("List forward: ");
    displayForward(head);
    return 0;
}
