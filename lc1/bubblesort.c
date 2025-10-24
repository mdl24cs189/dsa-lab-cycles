#include <stdio.h>
#include <time.h>

double bubble_sort(int a[], const int n) {
    clock_t t = clock();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] < a[j+1]) {
                const int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    t = clock() - t;
    return (double)t / CLOCKS_PER_SEC;
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double worst_case = bubble_sort(a, 10);
    double best_case = bubble_sort(b, 10);
    printf("Worst case: %f\n", worst_case);
    printf("Best case: %f\n", best_case);
    return 0;
}