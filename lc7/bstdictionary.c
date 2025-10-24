#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bnode {
	char word[50];
    char meaning[100];
	struct bnode* left;
	struct bnode* right;
};

struct bnode* createNewbnode(char word[], char meaning[]) {
	struct bnode* temp = (struct bnode*)malloc(sizeof(struct bnode));
    strcpy(temp->word, word);
    strcpy(temp->meaning, meaning);
    temp->left = temp->right = NULL;
    return temp;
}

struct bnode* insertIntoBST(struct bnode* root, char word[], char meaning[]) {
	if (root == NULL) {
		return createNewbnode(word, meaning);
	}
	if (strcmp(word, root->word) < 0) {
		root->left = insertIntoBST(root->left, word, meaning);
	} else {
		root->right = insertIntoBST(root->right, word, meaning);
	}
	
	return root;
}

void searchElement(struct bnode* root, char word[]) {
    struct bnode* current = root;
    while (current != NULL) {
        if (strcmp(word, current->word) == 0) {
            printf("Meaning: %s\n", current->meaning);
            break;
        } else if (strcmp(word, current->word) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current == NULL) {
        printf("Word not found in dictionary.\n");
    }    
}

int main() {
	struct bnode* root = NULL;
	
    while (1) {
        printf("Enter option:\n1. Insert word and meaning\n2. Search word\n3. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: {
                char word[50], meaning[100];
                printf("\nEnter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf(" %[^\n]s", meaning); // To read string with spaces
                root = insertIntoBST(root, word, meaning);
                break;
            }
            case 2: {
                char searchWord[50];
                printf("Enter word to search: ");
                scanf("%s", searchWord);
                searchElement(root, searchWord);
                break;
            }
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
	
	return 0;
}