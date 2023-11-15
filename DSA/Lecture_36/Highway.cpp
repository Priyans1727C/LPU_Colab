
#include <iostream>
using namespace std;

const int MAX_CITIES = 100;

bool hasChainOfHighways(int n, int highways[][MAX_CITIES], int city1, int city2) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                highways[i][j] = highways[i][j] || (highways[i][k] && highways[k][j]);
            }
        }
    }

    return highways[city1][city2];
}

int main() {
    int n;
    cin >> n;
    int highways[MAX_CITIES][MAX_CITIES] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> highways[i][j];
        }
    }

    int city1, city2;
    cin >> city1 >> city2;

    if (hasChainOfHighways(n, highways, city1, city2)) {
        cout << "There is a chain of highways connecting City " << city1 << " and City " << city2 << ".";
    } else {
        cout << "There is no chain of highways connecting City " << city1 << " and City " << city2 << ".";
    }

    return 0;
}
