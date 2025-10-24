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

int searchNode(int searchData) {
    struct Node* temp = head;
    int k = 0;
    while (temp != NULL) {
        if (temp->data == searchData) {
            return k;
        }
        temp = temp->next;
        k++;
    }
    printf("Node with data %d not found.\n", searchData);
    return -1;
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

    printf("Enter data of new node to search: ");
    int searchData;
    scanf("%d", &searchData);

    int position = searchNode(searchData);
    if (position != -1) {
        printf("Node with data %d found at position %d.\n", searchData, position);
    }
    return 0;
}