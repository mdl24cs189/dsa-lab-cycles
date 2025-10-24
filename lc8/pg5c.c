#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct QueueNode {
    int x, y, steps;
};

struct Queue {
    struct QueueNode items[MAX*MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front=-1; q->rear=-1;
    return q;
}

int isEmpty(struct Queue* q){ return q->rear==-1; }

void enqueue(struct Queue* q, int x, int y, int steps){
    if(q->rear==MAX*MAX-1) return;
    if(q->front==-1) q->front=0;
    q->items[++q->rear].x = x;
    q->items[q->rear].y = y;
    q->items[q->rear].steps = steps;
}

struct QueueNode dequeue(struct Queue* q){
    struct QueueNode temp = {-1,-1,-1};
    if(isEmpty(q)) return temp;
    temp = q->items[q->front];
    if(q->front==q->rear) q->front=q->rear=-1;
    else q->front++;
    return temp;
}

int visited[MAX][MAX];

int minSteps(int capX, int capY, int target){
    for(int i=0;i<=capX;i++)
        for(int j=0;j<=capY;j++)
            visited[i][j]=0;

    struct Queue* q = createQueue();
    enqueue(q,0,0,0);
    visited[0][0]=1;

    while(!isEmpty(q)){
        struct QueueNode node = dequeue(q);
        int x = node.x, y = node.y, steps = node.steps;
        if(x==target || y==target) return steps;

        int nextX[] = {capX, 0, x+y>capX?capX:x+y, x-(capY-y> x? x:capY-y), x, x};
        int nextY[] = {y, y, y-(capX-x>y? y:capX-x), y+(capY-y> x? x:capY-y), capY, 0};

        for(int i=0;i<6;i++){
            int nx = nextX[i], ny = nextY[i];
            if(!visited[nx][ny]){
                visited[nx][ny]=1;
                enqueue(q,nx,ny,steps+1);
            }
        }
    }
    return -1; // impossible
}

int main(){
    int capX, capY, target;
    printf("Enter capacities of jug X and Y, and target: ");
    scanf("%d%d%d",&capX,&capY,&target);
    int res = minSteps(capX,capY,target);
    if(res==-1) printf("Not possible\n");
    else printf("Minimum steps to reach target: %d\n",res);
    return 0;
}
