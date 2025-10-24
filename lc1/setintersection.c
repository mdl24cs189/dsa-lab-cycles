#include <stdio.h>

void intersection(int a[], int b[], int n1, int n2) {
	int c[n1+n2];
	int count = 0;
	if (n2 < n1) {
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < n1; j++) {
				if (a[j] == b[i]) {
					c[count] = b[i];
					count++;
					break;
				}
			}
		}
	} else {
		for (int i = 0; i < n1; i++) {
			// Search n1 times
			for (int j = 0; j < n2; j++) {
				// Search n2 times for element a[i]
				if (b[j] == a[i]) {
					c[count] = a[i];
					count++;
					break;
				}
			}
		}
	}
	printf("Intersection of sets: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
}

int main() {
	int s1[6] = {1, 2, 3, 4, 5, 6};
	int s2[4] = {2, 1, 3, 7};
	intersection(s1, s2, 6, 4);
	return 0;
}
