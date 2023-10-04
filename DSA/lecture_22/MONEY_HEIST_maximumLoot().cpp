#include <iostream>

using namespace std;

int maximumLoot(int houses[], int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return houses[0];
    }

    int prevMax = houses[0];
    int currMax = max(houses[0], houses[1]);

    for (int i = 2; i < n; i++) {
        int temp = currMax;
        currMax = max(houses[i] + prevMax, currMax);
        prevMax = temp;
    }

    return currMax;
}

int main() {
    int n;
    cin >> n;

    int houses[n];
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    int result = maximumLoot(houses, n);
    cout << result << endl;

    return 0;
}
