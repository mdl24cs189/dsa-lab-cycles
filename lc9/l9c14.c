#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

// Define a structure for Student
struct Student {
    char name[MAX_NAME_LEN];
    int marks;
};

// Function to swap two students
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort (decreasing order)
int partition(struct Student arr[], int low, int high) {
    int pivot = arr[high].marks;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].marks > pivot) { // for decreasing order
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort implementation
void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    struct Student students[MAX_STUDENTS];
    int n = 0;

    // Step 1: Read from input file
    inputFile = fopen("students.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s %d", students[n].name, &students[n].marks) == 2) {
        n++;
    }
    fclose(inputFile);

    // Step 2: Sort using Quick Sort
    quickSort(students, 0, n - 1);

    // Step 3: Write sorted data to output file
    outputFile = fopen("sorted_students.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Cannot create output file.\n");
        return 1;
    }

    fprintf(outputFile, "Name\tMarks\n");
    fprintf(outputFile, "------------------\n");

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s\t%d\n", students[i].name, students[i].marks);
    }

    fclose(outputFile);

    printf("Sorting completed. Check 'sorted_students.txt' for results.\n");
    return 0;
}