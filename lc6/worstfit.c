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

void worstFit(int reqSize) {
    struct Block* temp = head;
    struct Block* worst = NULL;
    int maxDiff = -1;
    while (temp != NULL) {
        if (temp->size >= reqSize && (temp->size - reqSize) > maxDiff) {
            maxDiff = temp->size - reqSize;
            worst = temp;
        }
        temp = temp->next;
    }
    if (worst) {
        printf("Allocated at start address %d\n", worst->start);
        worst->start += reqSize;
        worst->size -= reqSize;
        if (worst->size == 0) {
            struct Block* prev = head;
            if (worst == head) {
                head = worst->next;
                free(worst);
            } else {
                while (prev->next != worst) prev = prev->next;
                prev->next = worst->next;
                free(worst);
            }
        }
    } else {
        printf("No suitable block found\n");
    }
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
    worstFit(reqSize);
    printf("Blocks after allocation: ");
    display(head);
    return 0;
}
