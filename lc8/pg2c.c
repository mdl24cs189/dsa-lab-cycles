#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX], n, vertex;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter vertex to find adjacent vertices: ");
    scanf("%d", &vertex);

    printf("Vertices adjacent to %d: ", vertex);
    for (int i = 0; i < n; i++)
        if (adj[vertex][i])
            printf("%d ", i);
    printf("\n");

    return 0;
}
