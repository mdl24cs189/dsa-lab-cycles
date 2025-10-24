
#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX], n, vertex, directed;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Is the graph directed? (1 for yes / 0 for no): ");
    scanf("%d", &directed);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter vertex to find degree: ");
    scanf("%d", &vertex);

    int in = 0, out = 0;
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i]) out++;
        if (adj[i][vertex]) in++;
    }

    if (directed)
        printf("Vertex %d -> In-degree: %d, Out-degree: %d\n", vertex, in, out);
    else
        printf("Vertex %d -> Degree: %d\n", vertex, out);

    return 0;
}
