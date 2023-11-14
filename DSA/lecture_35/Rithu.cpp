
#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

int dfs(int node, int adj[][MAXN], int dp[], bool vis[], int n) {
    if (vis[node]) {
        return dp[node];
    }
    vis[node] = true;
    int maxPath = 0;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            maxPath = max(maxPath, 1 + dfs(i, adj, dp, vis, n));
        }
    }
    dp[node] = maxPath;
    return maxPath;
}

void addEdge(int adj[][MAXN], int u, int v) {
    adj[u][v] = 1;
}

int findLongestPath(int adj[][MAXN], int n) {
    int dp[MAXN] = {0};
    bool vis[MAXN] = {false};
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int pathLength = dfs(i, adj, dp, vis, n);
            maxLength = max(maxLength, pathLength);
        }
    }

    return maxLength;
}

int main() {
    int n, m;  
    cin >> n;
    
    int adj[MAXN][MAXN] = {0};
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u - 1, v - 1); 
    }

    int longestPath = findLongestPath(adj, n);
    cout << longestPath << endl;

    return 0;
}
