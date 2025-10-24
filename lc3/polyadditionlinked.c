#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

PolyNode *p1 = NULL, *p2 = NULL, *sum = NULL;

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

void appendNodeToSum(int coeff, int exp) {
    if (coeff == 0) return;
    PolyNode* newNode = createNode(coeff, exp);
    if (sum == NULL) {
        sum = newNode;
        return;
    }
    PolyNode* temp = sum;
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

void freeSum() {
    PolyNode* temp;
    while (sum != NULL) {
        temp = sum;
        sum = sum->next;
        free(temp);
    }
}

void addPolynomials() {
    PolyNode *t1 = p1, *t2 = p2;
    sum = NULL;
    while (t1 && t2) {
        if (t1->exp > t2->exp) {
            appendNodeToSum(t1->coeff, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            appendNodeToSum(t2->coeff, t2->exp);
            t2 = t2->next;
        } else {
            int s = t1->coeff + t2->coeff;
            if (s != 0)
                appendNodeToSum(s, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1) {
        appendNodeToSum(t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2) {
        appendNodeToSum(t2->coeff, t2->exp);
        t2 = t2->next;
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

    addPolynomials();
    printf("Sum of Polynomials: ");
    displayPolynomial(sum);
    printf("\n");

    freeP1();
    freeP2();
    freeSum();
    return 0;
}