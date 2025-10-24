#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void sortByMarks(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].marks < s[j].marks) { // Descending order
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void displayRankList(struct Student s[], int n) {
    printf("\nRank List:\n");
    printf("Rank\tRoll No\tName\t\tMarks\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%-15s%.2f\n", i + 1, s[i].rollNo, s[i].name, s[i].marks);
    }
}

void searchByRollNo(struct Student s[], int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if (s[i].rollNo == rollNo) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n", s[i].rollNo, s[i].name, s[i].marks);
            return;
        }
    }
    printf("\nStudent with Roll No %d not found.\n", rollNo);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks (out of 100): ");
        scanf("%f", &s[i].marks);
    }

    sortByMarks(s, n);
    displayRankList(s, n);

    int rollNo;
    printf("\nEnter a Roll No to search: ");
    scanf("%d", &rollNo);
    searchByRollNo(s, n, rollNo);

    return 0;
}
