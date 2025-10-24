#include <stdio.h>
#include <math.h>
#define MAX 30

int p1[MAX];
int p2[MAX];
int p3[MAX];

void initialisePolynomial(int poly[]) {
    for (int i = 0; i < MAX; i++) {
        poly[i] = 0;
    }
}

void displayPolynomial(int poly[]) {
    for (int i = MAX - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i != 0) {
                printf("+ ");
            }
        }
    }
}

int main() {
    int maxExp1, maxExp2, coeff, exp;
    printf("Enter the highest exponent for the first polynomial: ");
    scanf("%d", &maxExp1);
    initialisePolynomial(p1);
    for (int i = 0; i <= maxExp1; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        p1[i] = coeff;
    }
    printf("First Polynomial: ");
    displayPolynomial(p1);
    printf("\n");
    printf("Enter the highest exponent for the second polynomial: ");
    scanf("%d", &maxExp2);
    initialisePolynomial(p2);
    for (int i = 0; i <= maxExp2; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        p2[i] = coeff;
    }
    printf("Second Polynomial: ");
    displayPolynomial(p2);
    printf("\n");
    initialisePolynomial(p3);
    for (int i = 0; i < MAX; i++) {
        p3[i] = p1[i] + p2[i];
    }
    printf("Sum of Polynomials: ");
    displayPolynomial(p3);
    printf("\n");
    return 0;    
}