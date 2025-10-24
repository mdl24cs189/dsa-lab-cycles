#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = NULL;
    struct Node* curr = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;
        curr->next = newNode;
        curr = newNode;
    }
    struct Node* result = dummy->next;
    free(dummy);
    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;
    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    printf("Enter digits of first number in reverse order: ");
    struct Node* l1 = createList(n1);
    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);
    printf("Enter digits of second number in reverse order: ");
    struct Node* l2 = createList(n2);
    struct Node* sum = addTwoNumbers(l1, l2);
    printf("Sum as linked list: ");
    printList(sum);
    return 0;
}
