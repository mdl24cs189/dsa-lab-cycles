#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11

typedef struct Node {
    char name[100];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned long djb2(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = (hash*33) + c;
    }
    return hash;
}

void insert(char* name) {
    unsigned long hashValue = djb2(name);
    int index = hashValue % TABLE_SIZE;

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Inserted '%s' at index %d\n", name, index);
}

void search(char* name) {
    unsigned long hashValue = djb2(name);
    int index = hashValue % TABLE_SIZE;

    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Found '%s' at index %d\n", name, index);
            return;
        }
        current = current->next;
    }
    printf("'%s' not found\n", name);
}

void delete(char* name) {
    unsigned long hashValue = djb2(name);
    int index = hashValue % TABLE_SIZE;

    Node* current = hashTable[index];
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) prev->next = current->next;
            else hashTable[index] = current->next;
            free(current);
            printf("Deleted '%s' from index %d\n", name, index);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("'%s' not found to delete\n", name);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable[i];
        if (!current) { printf("Empty\n"); continue; }
        while (current) {
            printf("%s -> ", current->name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = NULL;

    int choice;
    char name[100];

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                printf("Enter name to insert: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0; 
                insert(name);
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                search(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                delete(name);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
