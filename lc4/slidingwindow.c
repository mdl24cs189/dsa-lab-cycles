#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL) {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL) {
        return -1;
    }
    struct node* temp = front;
    int dequeued = front->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return dequeued;
}

void clear_queue() {
    while (front != NULL) {
        dequeue();
    }
}

int main() {
    int n, k, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter window size k: ");
    scanf("%d", &k);
    for (i = 0; i <= n - k; i++) {
        int max = arr[i];
        clear_queue();
        for (j = i; j < i + k; j++) {
            enqueue(arr[j]);
            if (arr[j] > max) max = arr[j];
        }
        printf("%d ", max);
    }
    printf("\n");
    clear_queue();
    free(arr);
    return 0;
}
