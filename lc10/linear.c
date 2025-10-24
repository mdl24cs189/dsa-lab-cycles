#include <stdio.h>
#include <stdlib.h>

#define max 11

int hashTable[max];
int flag[max]; 

int hash(int key) {
    return key % max;
}

void insert(int key) {
    int index = hash(key);
    int startIndex = index;

    while (flag[index] == 1) {
        index = (index + 1) % max;
        if (index == startIndex) {
            printf("Hash Table is Full\n");
            return;
        }
    }

    hashTable[index] = key;
    flag[index] = 1;
    printf("Inserted key %d at index %d\n", key, index);
}

void search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (flag[index] != 0) {
        if (flag[index] == 1 && hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % max;
        if (index == startIndex) {
            break;
        }
    }

    printf("Key %d not found\n", key);
}

void delete(int key) {
    int index = hash(key);
    int startIndex = index;

    while (flag[index] != 0) {
        if (flag[index] == 1 && hashTable[index] == key) {
            flag[index] = -1; 
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        index = (index + 1) % max;
        if (index == startIndex) {
            break;
        }
    }

    printf("Key %d not found to delete\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < max; i++) {
        if (flag[i] == 1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else if (flag[i] == -1)
            printf("Index %d: Deleted\n", i);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    for (int i = 0; i < max; i++) {
        flag[i] = 0; 
    }

    int choice, key;
    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
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
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}