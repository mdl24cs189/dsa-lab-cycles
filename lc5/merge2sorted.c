#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* mergedHead = NULL;

void addNewNode1(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head1 == NULL || head1->data >= data) {
        newNode->next = head1;
        head1 = newNode;
        return;
    }

    struct Node* current = head1;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void addNewNode2(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head2 == NULL || head2->data >= data) {
        newNode->next = head2;
        head2 = newNode;
        return;
    }

    struct Node* current = head2;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void addNewNodeMerged(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (mergedHead == NULL || mergedHead->data >= data) {
        newNode->next = mergedHead;
        mergedHead = newNode;
        return;
    }

    struct Node* current = mergedHead;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertMergedList() {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data < ptr2->data) {
            addNewNodeMerged(ptr1->data);
            ptr1 = ptr1->next;
        } else {
            addNewNodeMerged(ptr2->data);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        addNewNodeMerged(ptr1->data);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        addNewNodeMerged(ptr2->data);
        ptr2 = ptr2->next;
    }

    struct Node* temp = mergedHead;
    printf("Merged Sorted List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2;
    printf("Enter number of nodes for list 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        addNewNode1(data);
    }
    struct Node* temp1 = head1;
    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");

    printf("Enter number of nodes for list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        addNewNode2(data);
    }
    struct Node* temp2 = head2;
    while (temp2 != NULL) {
        printf("%d -> ", temp2->data);
        temp2 = temp2->next;
    }
    printf("NULL\n");

    insertMergedList();
    return 0;
}