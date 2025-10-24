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
        addEdge(adj, v, u); // undirected
    }

    printf("Enter vertex to find degree: ");
    scanf("%d", &vertex);

    int degree = 0;
    struct Node* temp = adj[vertex];
    while (temp) {
        degree++;
        temp = temp->next;
    }

    printf("Degree of vertex %d: %d\n", vertex, degree);
    return 0;
}
