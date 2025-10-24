
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

PolyNode *p1 = NULL, *p2 = NULL, *product = NULL;

PolyNode* createNode(int coeff, int exp) {
    PolyNode* node = (PolyNode*)malloc(sizeof(PolyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void appendNodeToP1(int coeff, int exp) {
    if (coeff == 0) return;
    PolyNode* newNode = createNode(coeff, exp);
    if (p1 == NULL) {
        p1 = newNode;
        return;
    }
    PolyNode* temp = p1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void appendNodeToP2(int coeff, int exp) {
    if (coeff == 0) return;
    PolyNode* newNode = createNode(coeff, exp);
    if (p2 == NULL) {
        p2 = newNode;
        return;
    }
    PolyNode* temp = p2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void appendNodeToProduct(int coeff, int exp) {
    if (coeff == 0) return;
    PolyNode* newNode = createNode(coeff, exp);
    if (product == NULL) {
        product = newNode;
        return;
    }
    PolyNode* temp = product;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(PolyNode *head) {
    PolyNode* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf("+ ");
        printf("%dx^%d ", temp->coeff, temp->exp);
        first = 0;
        temp = temp->next;
    }
    if (first) printf("0");
}

void freeP1() {
    PolyNode* temp;
    while (p1 != NULL) {
        temp = p1;
        p1 = p1->next;
        free(temp);
    }
}

void freeP2() {
    PolyNode* temp;
    while (p2 != NULL) {
        temp = p2;
        p2 = p2->next;
        free(temp);
    }
}

void freeProduct() {
    PolyNode* temp;
    while (product != NULL) {
        temp = product;
        product = product->next;
        free(temp);
    }
}

void multiplyPolynomials() {
    PolyNode *t1 = p1;
    product = NULL;
    
    while (t1 != NULL) {
        PolyNode *t2 = p2;
        while (t2 != NULL) {
            int newCoeff = t1->coeff * t2->coeff;
            int newExp = t1->exp + t2->exp;
            
            PolyNode *temp = product;
            PolyNode *prev = NULL;
            while (temp != NULL && temp->exp > newExp) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp != NULL && temp->exp == newExp) { // Matching coefficients
                temp->coeff += newCoeff;
                if (temp->coeff == 0) {
                    if (prev == NULL) {
                        product = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    free(temp);
                }
            } else { // No matching coefficients
                if (newCoeff != 0) {
                    PolyNode *newNode = createNode(newCoeff, newExp);
                    if (prev == NULL) {
                        newNode->next = product;
                        product = newNode;
                    } else {
                        newNode->next = prev->next;
                        prev->next = newNode;
                    }
                }
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

void inputPolynomialP1(int maxExp) {
    int coeff;
    for (int i = maxExp; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
            appendNodeToP1(coeff, i);
    }
}

void inputPolynomialP2(int maxExp) {
    int coeff;
    for (int i = maxExp; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
            appendNodeToP2(coeff, i);
    }
}

int main() {
    int maxExp1, maxExp2;

    printf("Enter the highest exponent for the first polynomial: ");
    scanf("%d", &maxExp1);
    inputPolynomialP1(maxExp1);
    printf("First Polynomial: ");
    displayPolynomial(p1);
    printf("\n");

    printf("Enter the highest exponent for the second polynomial: ");
    scanf("%d", &maxExp2);
    inputPolynomialP2(maxExp2);
    printf("Second Polynomial: ");
    displayPolynomial(p2);
    printf("\n");

    multiplyPolynomials();
    printf("Product of Polynomials: ");
    displayPolynomial(product);
    printf("\n");

    freeP1();
    freeP2();
    freeProduct();
    return 0;
}