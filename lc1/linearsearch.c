#include <stdio.h>
#include <time.h>

int linear_search(int a[], int n, int b) {
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Worst case:
    clock_t t1 = clock();
    linear_search(a, 10, 9);
    t1 = clock() - t1;
    printf("Worst case scenario: %f\n", ((double)t1) / CLOCKS_PER_SEC);
    // Best case:
    clock_t t2 = clock();
    linear_search(b, 10, 1);
    t2 = clock() - t2;
    printf("Best case scenario: %f\n", ((double)t2) / CLOCKS_PER_SEC);
    return 0;
}