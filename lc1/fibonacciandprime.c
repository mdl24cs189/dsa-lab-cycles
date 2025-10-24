#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    long long int a = 0, b = 1, sum;
    printf("Fibonacci upto %d:\n", n);
    for (int i = 2; i < n; i++) {
        sum = a + b;
        printf("%lld\n", a);
        a = b;
        b = sum;
        if (a > 100) {
        	return;
        }
    }
}

void prime_upto(int n) {
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        int is_prime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d\n", i);
        }
    }
}

void main() {
    while (1) {
        int ch;
        printf("Enter an option:\n");
        printf("0: Fibonacci numbers upto 100\n");
        printf("1: Prime numbers upto 100\n");
        printf("2: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                fibonacci(100);
                break;
            case 1:
                prime_upto(100);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }
}
