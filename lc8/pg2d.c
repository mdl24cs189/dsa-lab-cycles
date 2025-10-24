#include <stdio.h>
#define MAX 10

int main() {
    int adj[MAX][MAX], n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int complete = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && adj[i][j] == 0) {
                complete = 0;
                break;
            }

    printf("Graph is %scomplete\n", complete ? "" : "not ");
    return 0;
}
