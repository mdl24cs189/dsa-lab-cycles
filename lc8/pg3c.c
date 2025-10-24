#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, e, u, v, x, y;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    printf("Enter two vertices to check connection (x y): ");
    scanf("%d%d", &x, &y);

    int connected = 0;
    struct Node* temp = adj[x];
    while (temp) {
        if (temp->vertex == y) {
            connected = 1;
            break;
        }
        temp = temp->next;
    }

    if (connected)
        printf("Vertices %d and %d are directly connected\n", x, y);
    else
        printf("Vertices %d and %d are not directly connected\n", x, y);

    return 0;
}
