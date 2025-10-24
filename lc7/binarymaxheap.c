#include <stdio.h>
#define MAX 15

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] != -1 && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] != -1 && arr[right] > arr[largest]) largest = right;
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            printf("_ ");
            continue;
        }
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[MAX] = { 30, 20, 40, 15, 25, 35, 50, 5, 18, -1, -1, -1, -1, 45, 60 };
    printf("Before heapify:\n");
    display(data, MAX);
    buildMaxHeap(data, MAX);
    printf("After heapify:\n");
    display(data, MAX);
    return 0;
}