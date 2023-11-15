
#include <iostream>
using namespace std;
#define MAX_FLIGHTS 100

bool canCreateFlightSchedule(int n, int constraints[][2]) {
    // Creating an adjacency matrix to represent dependencies
    int adjMatrix[MAX_FLIGHTS][MAX_FLIGHTS] = {0};

    for (int i = 0; i < n; ++i) {
        int from = constraints[i][0];
        int to = constraints[i][1];
        adjMatrix[from][to] = 1;
    }

    // Applying Warshall's algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adjMatrix[i][j] = adjMatrix[i][j] || (adjMatrix[i][k] && adjMatrix[k][j]);
            }
        }
    }

    // Checking for circular dependencies
    for (int i = 0; i < n; ++i) {
        if (adjMatrix[i][i]) {
            return false; // Circular dependency found
        }
    }

    return true; // No circular dependencies
}

int main() {
    int n;
    cin >> n;
    int constraints[MAX_FLIGHTS][2];

    for (int i = 0; i < n; ++i) {
        cin >> constraints[i][0] >> constraints[i][1];
    }

    if (canCreateFlightSchedule(n, constraints)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
