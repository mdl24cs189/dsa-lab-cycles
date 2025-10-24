#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX], n, directed;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Is the graph directed? (1 for yes / 0 for no): ");
    scanf("%d", &directed);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j]) count++;

    if (!directed) count /= 2;

    printf("Total number of edges: %d\n", count);
    return 0;
}
