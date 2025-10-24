#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

PolyNode* polynomial = NULL;

PolyNode* createNode(int coeff, int exp) {
    PolyNode* node = (PolyNode*)malloc(sizeof(PolyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insertTerm(int coeff, int exp) {
    PolyNode* newNode = createNode(coeff, exp);
    if (polynomial == NULL) {
        polynomial = newNode;
        return;
    }
    PolyNode* temp = polynomial;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

double evaluatePolynomial(double x) {
    double result = 0.0;
    PolyNode* temp = polynomial;
    while (temp) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

void displayPolynomial() {
    PolyNode* temp = polynomial;
    while (temp) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

void freePolynomial() {
    PolyNode* temp;
    while (polynomial) {
        temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }
}

int main() {
    int choice = 0;

	while (0 < 1) {
		printf("1. Initialise Polynomial\n2. Display\n3. Evaluate\n4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter highest power of polynomial: ");
				int max_power = 1;
				scanf("%d", &max_power);
				for (int i = 0; i <= max_power; i++) {
					int coeff;
					printf("Coefficient for x^%d: ", i);
					scanf("%d", &coeff);
					insertTerm(coeff, i);
				}
				break;
			case 2:
				displayPolynomial();
				break;
			case 3:
				printf("Enter value of x to evaluate polynomial: ");
				double x;
				scanf("%lf", &x);
				printf("Polynomial evaluated at x=%.2f: %.2f\n", x, evaluatePolynomial(x));
				break;
			case 4:
				freePolynomial();
				exit(0);
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
	}
}