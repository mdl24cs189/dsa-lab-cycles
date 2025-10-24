#include <stdio.h>
#include <math.h>

int is_prime(const long long int a) {
    if (a < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void prime_fibonacci(const int n) {
    long long int a = 0, b = 1, sum;
    printf("Fibonacci upto %d:\n", n);
    for (int i = 2; i < n; i++) {
        sum = a + b;
        a = b;
        b = sum;
        if (is_prime(b)) {
            printf("%lld\n", b);
        }
    }
}

int main() {
    prime_fibonacci(100);
}