#include <stdio.h>
#include <stdlib.h>

struct Block {
    int start;
    int size;
    struct Block* next;
};

struct Block* head = NULL;

struct Block* createBlock(int start, int size) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->start = start;
    newBlock->size = size;
    newBlock->next = NULL;
    return newBlock;
}

void append(int start, int size) {
    struct Block* newBlock = createBlock(start, size);
    if (head == NULL) {
        head = newBlock;
        return;
    }
    struct Block* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newBlock;
}

void display(struct Block* node) {
    struct Block* temp = node;
    while (temp != NULL) {
        printf("[Start: %d, Size: %d] ", temp->start, temp->size);
        temp = temp->next;
    }
    printf("\n");
}

void firstFit(int reqSize) {
    struct Block* temp = head;
    while (temp != NULL) {
        if (temp->size >= reqSize) {
            printf("Allocated at start address %d\n", temp->start);
            temp->start += reqSize;
            temp->size -= reqSize;
            if (temp->size == 0) {
                struct Block* prev = head;
                if (temp == head) {
                    head = temp->next;
                    free(temp);
                } else {
                    while (prev->next != temp) prev = prev->next;
                    prev->next = temp->next;
                    free(temp);
                }
            }
            return;
        }
        temp = temp->next;
    }
    printf("No suitable block found\n");
}

int main() {
    int n, start, size, reqSize;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter start and size for block %d: ", i + 1);
        scanf("%d %d", &start, &size);
        append(start, size);
    }
    printf("Blocks before allocation: ");
    display(head);
    printf("Enter size of file to allocate: ");
    scanf("%d", &reqSize);
    firstFit(reqSize);
    printf("Blocks after allocation: ");
    display(head);
    return 0;
}
