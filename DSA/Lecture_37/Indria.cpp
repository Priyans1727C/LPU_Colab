#include <stdio.h>
#include <limits.h>

#define MAXN 100
#define INF 10000000

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && (dis[i][k] + dis[k][j] < dis[i][j])) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void printPath(int path[], int n) {
    for (int i = 0; i < n - 1; i++)
        printf("%d -> ", path[i]);
    printf("%d", path[n - 1]);
}

int main() {
    int V;
    scanf("%d", &V);
    
    int graph[MAXN][MAXN];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u, v;
    scanf("%d %d", &u, &v);

    int path[MAXN];
    path[0] = u;
    int index = 1;
    
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    printf("Shortest path from %d to %d: ", path[0], path[index - 1]);
    printPath(path, index);

    return 0;
}
