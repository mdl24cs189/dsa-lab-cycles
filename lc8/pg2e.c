#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX], n, x, y;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter two vertices to check edge (x y): ");
    scanf("%d%d", &x, &y);

    if (adj[x][y])
        printf("Edge exists between %d and %d\n", x, y);
    else
        printf("No edge between %d and %d\n", x, y);

    return 0;
}
