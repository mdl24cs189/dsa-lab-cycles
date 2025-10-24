#include <stdio.h>

void bsort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j+1]) {
				// Swap
				const int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}		
		}
	}
}

float mean(int a[], int n) {
	float sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum / n;
}

float median(int a[], int n) {
	const int i = n/2;
	if (n % 2 == 0) {
		return (a[i] + a[i-1]) / 2;
	}
	return a[i];
}

int mode(int a[], int n) {
	int count = 0;
	int max_count = 0;
	int current = a[0];
	int max_current = a[0];
	for (int i = 0; i < n; i++) {
		if (current != a[i]) {
			if (count > max_count) {
				max_count = count;
				max_current = current;
			}
			count = 0;
			current = a[i];
		} else {
			count++;
		}
	}
	return max_current;
}

int main() {
	const int n = 8;
	int a[] = {2, 2, 3, 1, 3, 4, 2, 2};
	printf("Original data: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	bsort(a, n);
	printf("Sorted data: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Mean: %3.2f\n", mean(a, n));
	printf("Median: %3.2f\n", median(a, n));
	printf("Mode: %d\n", mode(a, n));
}
