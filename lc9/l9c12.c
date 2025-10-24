#include <stdio.h>
#include <string.h>

void sortNames(char names[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    char names[n][50];

    printf("Enter the names of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", names[i]); // reads single word names
    }

    printf("\nOriginal List of Names:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    sortNames(names, n);

    printf("\nSorted List of Names (Alphabetical Order):\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    return 0;
}
