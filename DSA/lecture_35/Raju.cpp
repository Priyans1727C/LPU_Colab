#include <stdio.h>
#define MAX_SIZE 100

int dfs(int adjMatrix[][MAX_SIZE], int n, int start, int end, int visited[MAX_SIZE]) {
    if (start == end)
        return 1;
    visited[start] = 1;
    for (int i = 0; i < n; ++i) {
        if (adjMatrix[start][i] && !visited[i] && dfs(adjMatrix, n, i, end, visited))
            return 1;
    }
    return 0;
}

int validPath(int n, int edges[][2], int m, int start, int end) {
    int adjMatrix[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < m; ++i) {
        adjMatrix[edges[i][0]][edges[i][1]] = 1;
    }

    int visited[MAX_SIZE] = {0};
    if (dfs(adjMatrix, n, start, end, visited)) {
        printf("There is a path from %d to %d\n", start, end);
        return 1;
    } else {
        printf("There is no path from %d to %d\n", start, end);
        return 0;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int edges[MAX_SIZE][2];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    int start, end;
    scanf("%d %d", &start, &end);

    validPath(n, edges, m, start, end);

    return 0;
}
