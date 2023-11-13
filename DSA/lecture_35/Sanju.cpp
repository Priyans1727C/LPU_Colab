
#include <iostream>
using namespace std;

#define MAX_V 100

void enqueue(int* queue, int& rear, int vertex) {
    queue[++rear] = vertex;
}

int dequeue(int* queue, int& front) {
    return queue[++front];
}

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    int visited[MAX_V] = {0};
    int queue[MAX_V];
    int front = -1, rear = -1;

 
    
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            enqueue(queue, rear, i);
            visited[i] = 1;

            while (front != rear) {
                int current = dequeue(queue, front);
                cout << current << " ";

                for (int j = 0; j < V; ++j) {
                    if (adjList[current][j] && !visited[j]) {
                        enqueue(queue, rear, j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }

    bfsOfGraph(V, adjList);

    return 0;
}
