#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[100];
    float mark;
    struct Student* next;
};

struct Student* head = NULL;

void insertStudent(int rollno, const char* name, float mark) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollno = rollno;
    strcpy(newStudent->name, name);
    newStudent->mark = mark;
    newStudent->next = NULL;
    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void deleteStudent(int rollno) {
    struct Student *temp = head, *prev = NULL;
    while (temp != NULL && temp->rollno != rollno) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void modifyStudent(int rollno, const char* name, float mark) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollno == rollno) {
            strcpy(temp->name, name);
            temp->mark = mark;
            return;
        }
        temp = temp->next;
    }
}

struct Student* searchStudent(int rollno) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollno == rollno) return temp;
        temp = temp->next;
    }
    return NULL;
}

void printStudents() {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s, Mark: %.2f\n", temp->rollno, temp->name, temp->mark);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Modify\n4. Search\n5. Print\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int rollno;
            char name[100];
            float mark;
            printf("Enter rollno, name, mark: ");
            scanf("%d %s %f", &rollno, name, &mark);
            insertStudent(rollno, name, mark);
        } else if (choice == 2) {
            int rollno;
            printf("Enter rollno to delete: ");
            scanf("%d", &rollno);
            deleteStudent(rollno);
        } else if (choice == 3) {
            int rollno;
            char name[100];
            float mark;
            printf("Enter rollno to modify, new name, new mark: ");
            scanf("%d %s %f", &rollno, name, &mark);
            modifyStudent(rollno, name, mark);
        } else if (choice == 4) {
            int rollno;
            printf("Enter rollno to search: ");
            scanf("%d", &rollno);
            struct Student* s = searchStudent(rollno);
            if (s) {
                printf("Found: Roll No: %d, Name: %s, Mark: %.2f\n", s->rollno, s->name, s->mark);
            } else {
                printf("Student not found\n");
            }
        } else if (choice == 5) {
            printStudents();
        } else if (choice == 6) {
            break;
        }
    }
    return 0;
}
