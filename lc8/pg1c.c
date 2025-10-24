#include <stdio.h>
#define MAX 10

int main() {
    int inc[MAX][MAX], v, e;

    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter incidence matrix (%d x %d):\n", v, e);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < e; j++)
            scanf("%d", &inc[i][j]);

    printf("\nIncidence Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++)
            printf("%d ", inc[i][j]);
        printf("\n");
    }

    return 0;
}
