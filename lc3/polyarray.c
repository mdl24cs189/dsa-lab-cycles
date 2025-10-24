#include <stdio.h>
#include <math.h>
#define MAX 30

int p[MAX];

void initialisePolynomial() {
	for (int i = 0; i < MAX; i++) {
		p[i] = 0;
	}
}

int evaluatePolynomial(int value, int limit) {
	int sum = 0;
	for (int i = limit; i >= 0; i--) {
		sum += p[i] * pow(value, i);
	}
	return sum;
}

int main() {
	int limit, val;
	printf("Enter highest power of polynomial: ");
	scanf("%d", &limit);
	initialisePolynomial();
	for (int i = limit; i >= 0; i--) {
		printf("Enter coefficient of x^%d term: ", i);
		scanf("%d", &p[i]);
	}
	printf("Given polynomial is: ");
	for (int i = limit; i > 0; i--) {
		printf("%dx^%d + ", p[i], i);
	}
	printf("%d\n", p[0]);
	printf("Enter value of x: ");
	scanf("%d", &val);
	printf("Value of evaluated polynomial: %d\n",evaluatePolynomial(val, limit));
}