#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define WORD_LEN 50

typedef struct Node {
    char word[WORD_LEN];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = hash*33 + c;
    return hash % TABLE_SIZE;
}

void insert(const char* word) {
    unsigned int index = hash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(const char* word) {
    unsigned int index = hash(word);
    Node* curr = hashTable[index];
    while (curr) {
        if (strcmp(curr->word, word) == 0)
            return 1;
        curr = curr->next;
    }
    return 0;
}



int main() {
    char* dictionary[] = {
    "apple", "banana", "orange", "grape", "pear",
    "dog", "cat", "mouse", "rabbit", "lion",
    "book", "pen", "pencil", "notebook", "eraser",
    "car", "bus", "train", "bicycle", "airplane"
    };

    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < dictSize; i++) {
        insert(dictionary[i]);
    }

    char word[WORD_LEN];
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (search(word)) {
        printf("'%s' is spelled correctly.\n", word);
    } else {
        printf("'%s' is NOT in dictionary.\n", word);
    }

    return 0;
}