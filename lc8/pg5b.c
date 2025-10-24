#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct QueueNode {
    int x, y;
};

struct Queue {
    struct QueueNode items[MAX*MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1; q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int x, int y) {
    if (q->rear == MAX*MAX -1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear].x = x;
    q->items[q->rear].y = y;
}

struct QueueNode dequeue(struct Queue* q) {
    struct QueueNode temp = {-1,-1};
    if (isEmpty(q)) return temp;
    temp = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return temp;
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
    int rows, cols;
    printf("Enter grid size (rows cols): ");
    scanf("%d%d", &rows, &cols);

    int grid[MAX][MAX];
    int dist[MAX][MAX];

    printf("Enter grid (0=empty,1=mine):\n");
    struct Queue* q = createQueue();
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            scanf("%d",&grid[i][j]);
            dist[i][j] = -1;
            if(grid[i][j]==1){
                enqueue(q,i,j);
                dist[i][j]=0;
            }
        }

    while(!isEmpty(q)){
        struct QueueNode node = dequeue(q);
        for(int k=0;k<4;k++){
            int nx = node.x + dx[k];
            int ny = node.y + dy[k];
            if(nx>=0 && nx<rows && ny>=0 && ny<cols && dist[nx][ny]==-1){
                dist[nx][ny] = dist[node.x][node.y]+1;
                enqueue(q,nx,ny);
            }
        }
    }

    printf("Distance from nearest mine:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }

    return 0;
}
