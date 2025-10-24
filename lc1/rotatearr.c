#include <stdio.h>

void rotate(int a[], int n, char d, int cr) {
	int b[n];
	if (d == 'l') {
		// Left shift
		for (int i = 0; i < cr; i++) {
			for (int j = 0; j < n-1; j++) {
				b[j] = a[j+1];
			}
			b[n-1] = a[0];
			for (int j = 0; j < n; j++) {
				a[j] = b[j];
			}
		}
	} else if (d == 'r') {
		// Right shift
		for (int i = 0; i < cr; i++) {
			for (int j = 1; j < n; j++) {
				b[j] = a[j-1];
			}
			b[0] = a[n-1];
			for (int j = 0; j < n; j++) {
				a[j] = b[j];
			}
		}
	} else {
		printf("Invalid direction.\n");
		return;
	}
}

int main() {
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	printf("Original array: ");
	for (int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	rotate(a, 7, 'l', 3);
	printf("Shifted array: ");
	for (int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
