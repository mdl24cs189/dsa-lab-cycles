#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];
    
    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1; 
}

void delete(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;
    
    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;
            
            free(temp);
            printf("Deleted key %d\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found!\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("(%d,%d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key, value;
    
    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d%d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(key);
                if (value != -1)
                    printf("Found: Value = %d\n", value);
                else
                    printf("Key not found!\n");
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
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