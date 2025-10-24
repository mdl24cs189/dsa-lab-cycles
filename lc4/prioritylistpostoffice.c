#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enqueue(char x[], int pr) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(temp->data, x);
    temp->priority = pr;
    temp->next = NULL;

    if (front == NULL || pr > front->priority) {
        temp->next = front;
        front = temp;
    } else {
        struct node* current = front;
        while (current->next != NULL && current->next->priority >= pr) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue empty.\n");
        return;
    }
    struct node* temp = front;
    front = front->next;
    printf("Serving customer: %s with priority %d\n", temp->data, temp->priority);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue empty.\n");
        return;
    }
    printf("Queue content:\n");
    struct node* temp = front;
    while (temp != NULL) {
        printf("%s (%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    char cust_name[50];
    int priority;
    while (1) {
        printf("\n\nMenu: (Choices 1-4)\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        printf("Enter option: ");
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        switch (ch) {
            case 1:
                printf("Enter customer name: ");
                fgets(cust_name, sizeof(cust_name), stdin);
                cust_name[strcspn(cust_name, "\n")] = 0;
                printf("Enter customer category\n(4 - Differently abled)\n(3 - Senior citizen)\n");
                printf("(2 - Defence Personnel)\n(1 - Ordinary)\n: ");
                scanf("%d", &priority);
                while(getchar() != '\n');
                if (priority > 4 || priority < 1) {
                    printf("Invalid category.\n");
                    break;
                }
                enqueue(cust_name, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}
