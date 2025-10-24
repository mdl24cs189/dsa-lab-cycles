#include <stdio.h>
#define MAX 10

int visited[MAX];

int cycleFound = 0;
int n;
int adj[MAX][MAX];

void dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i])
                dfs(i, v);
            else if (i != parent)
                cycleFound = 1;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, -1);

    printf("Graph %s a cycle\n", cycleFound ? "has" : "does not have");

    return 0;
}
