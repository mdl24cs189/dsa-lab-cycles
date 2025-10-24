#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void addNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteSmallest() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* minNode = head;
    struct Node* prevMinNode = NULL;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data < minNode->data) {
            minNode = temp;
            prevMinNode = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    if (prevMinNode == NULL) { // Special case: minNode is head
        head = head->next;
    } else {
        prevMinNode->next = minNode->next;
    }
    free(minNode);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        addNewNode(data);
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Deleting the smallest node:\n");
    deleteSmallest();

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}