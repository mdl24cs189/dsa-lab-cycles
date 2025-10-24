#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX] = {0};  // initialize matrix with 0
    int n, e;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);

        // since undirected graph, mark both [u][v] and [v][u] as 1
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
