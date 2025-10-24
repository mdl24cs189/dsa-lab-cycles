#include <stdio.h>

int main() {
    const int a[9] = {3, 2, 5, 7, 8, 1, 6, 9};
    printf("Local maximas: ");
    for (int i = 1; i < 8; i++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    return 0;
}
