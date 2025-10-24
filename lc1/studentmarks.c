#include <stdio.h>

void bsort(int a[], const int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] < a[j+1]) {
                const int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void insert_mark(int a[], const int n, const int mark) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= mark) {
            for (int j = n; j > i; j--) {
                a[j] = a[j-1];
            }
            a[i] = mark;
            break;
        }
    }
}

int main() {
    const int n = 10;
    int marks[11] = {36, 38, 37, 23, 22, 29, 40, 36, 19, 35};

    // Display original and sorted data:
    printf("Original marks: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
    bsort(marks, n);
    printf("Sorted marks: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
    // Insert new marks
    int new_mark;
    printf("Enter marks: ");
    scanf("%d", &new_mark);
    insert_mark(marks, n, new_mark);
    printf("Modified marks: ");
    for (int i = 0; i < n+1; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
    return 0;
}
