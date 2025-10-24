#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

void DFSUtil(struct Node* adj[], int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            DFSUtil(adj, temp->vertex, visited);
        temp = temp->next;
    }
}

void DFS(struct Node* adj[], int start, int n) {
    int visited[MAX] = {0};
    printf("DFS traversal: ");
    DFSUtil(adj, start, visited);
    printf("\n");
}

int main() {
    int n, e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); // undirected
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    DFS(adj, start, n);
    return 0;
}
