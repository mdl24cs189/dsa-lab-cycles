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
    int n, e, u, v, vertex;
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
        addEdge(adj, v, u); // For undirected graph
    }

    printf("Enter vertex to find neighbours: ");
    scanf("%d", &vertex);

    printf("Neighbours of %d: ", vertex);
    struct Node* temp = adj[vertex];
    while (temp) {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
