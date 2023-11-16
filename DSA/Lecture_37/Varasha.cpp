#include <stdio.h>
#define INF 10000000
#define MAXN 10

void initialise(int V, int graph[MAXN][MAXN], int dis[MAXN][MAXN], int Next[MAXN][MAXN]) {
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

void floydWarshall(int V, int dis[MAXN][MAXN], int Next[MAXN][MAXN]) {
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
    printf("%d\n", path[n - 1]);
}

int main() {
    int V;
    scanf("%d", &V);

    int graph[MAXN][MAXN];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int dis[MAXN][MAXN];
    int Next[MAXN][MAXN];
    initialise(V, graph, dis, Next);
    floydWarshall(V, dis, Next);

    int u = 0; 
    int v = V - 1;
    
    int path[MAXN];
    path[0] = u;
    int index = 1;
    
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    printPath(path, index);

    return 0;
}
