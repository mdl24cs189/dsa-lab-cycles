#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Page {
    char uri[256];
    struct Page* prev;
    struct Page* next;
};

struct Page* head = NULL;
struct Page* current = NULL;

struct Page* createPage(const char* uri) {
    struct Page* newPage = (struct Page*)malloc(sizeof(struct Page));
    strcpy(newPage->uri, uri);
    newPage->prev = NULL;
    newPage->next = NULL;
    return newPage;
}

void visit(const char* uri) {
    struct Page* newPage = createPage(uri);
    if (head == NULL) {
        head = current = newPage;
        return;
    }
    if (current->next) {
        struct Page* temp = current->next;
        while (temp) {
            struct Page* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = NULL;
    }
    newPage->prev = current;
    current->next = newPage;
    current = newPage;
}

void goBack() {
    if (current && current->prev) current = current->prev;
}

void goForward() {
    if (current && current->next) current = current->next;
}

void displayCurrent() {
    if (current) printf("Current URI: %s\n", current->uri);
    else printf("No page loaded\n");
}

int main() {
    int choice;
    char uri[256];
    while (1) {
        printf("1. Visit new page\n2. Go back\n3. Go forward\n4. Display current page\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter URI: ");
                scanf("%s", uri);
                visit(uri);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrent();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
