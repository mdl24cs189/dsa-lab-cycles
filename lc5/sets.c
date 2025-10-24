#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head1 = NULL;
struct Node* head2 = NULL;

void addNewNode1(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head1 == NULL) {
        head1 = newNode;
        return;
    } else {
        struct Node* temp = head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addNewNode2(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head2 == NULL) {
        head2 = newNode;
        return;
    } else {
        struct Node* temp = head2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void findUnionElements() {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    int found[100] = {0};
    int i = 0;

    printf("Union of two sets: ");
    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
        found[++i] = temp1->data;
    }
    while (temp2 != NULL) {
        int j, flag = 0;
        for (j = 1; j <= i; j++) {
            if (temp2->data == found[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d -> ", temp2->data);
            found[++i] = temp2->data;
        }
        temp2 = temp2->next;
    }
}

void findIntersectionElements() {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    int found[100] = {0};
    int i = 0, j;

    while (temp1 != NULL) {
        found[++i] = temp1->data;
        temp1 = temp1->next;
    }

    printf("Intersection of two sets: ");
    while (temp2 != NULL) {
        for (j = 1; j <= i; j++) {
            if (temp2->data == found[j]) {
                printf("%d -> ", temp2->data);
                break;
            }
        }
        temp2 = temp2->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2;
    printf("Enter number of nodes for set 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int data;
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);
        addNewNode1(data);
    }
    struct Node* temp1 = head1;
    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");

    printf("Enter number of nodes for set 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int data;
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);
        addNewNode2(data);
    }
    struct Node* temp2 = head2;
    while (temp2 != NULL) {
        printf("%d -> ", temp2->data);
        temp2 = temp2->next;
    }
    printf("NULL\n");

    findIntersectionElements();
    findUnionElements();

    return 0;
}