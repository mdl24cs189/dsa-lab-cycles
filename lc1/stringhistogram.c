#include <stdio.h>

void bsort(char a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j+1]) {
				// Swap
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}		
		}
	}
}

void freq(char a[], int n) {
	int count = 0;
	int current = a[0];
	for (int i = 0; i < n; i++) {
		if (current != a[i]) {
			if (current != ' ') { // Skip blank character
				printf("%c - %d\n", current, count);
			}
			count = 0;
			current = a[i];
		}
		count++;
	}
}

int main() {
	const int n = 11;
	char a[11] = "Hello world";
	printf("String: %s\n", a);
	bsort(a, n);
	freq(a, n);
	return 0;
}
