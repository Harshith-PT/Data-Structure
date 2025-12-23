
#include <stdio.h>

int n;
int graph[20][20];
int visited[20];
int queue[20];
int front = -1, rear = -1;


void bfs(int start) {
    int i;
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (i = 0; i < n; i++) {
            if (graph[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start);

    return 0;
}
