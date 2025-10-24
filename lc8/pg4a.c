#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int vertex;
    struct Node* next;
};

// Queue for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int value = q->items[q->front];
    if (q->front >= q->rear) q->front = q->rear = -1;
    else q->front++;
    return value;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(struct Node* adj[], int start, int n) {
    int visited[MAX] = {0};
    struct Queue* q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    printf("BFS traversal: ");
    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }
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

    BFS(adj, start, n);
    return 0;
}
