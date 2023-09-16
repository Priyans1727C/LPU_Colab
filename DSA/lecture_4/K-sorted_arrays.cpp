// You are using GCC
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> mergeSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<int> pq;

    for (const vector<int>& array : arrays) {
        for (int num : array) {
            pq.push(num);
        }
    }

    vector<int> mergedSorted;

    while (!pq.empty()) {
        mergedSorted.push_back(pq.top());
        pq.pop();
    }

    return mergedSorted;
}

int main() {
    int K;
    cin >> K;

    vector<vector<int>> arrays(K);

    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        arrays[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> arrays[i][j];
        }
    }

    vector<int> result = mergeSortedArrays(arrays);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
