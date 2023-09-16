// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    vector<int> arr2(m);

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = mergeSortedArrays(arr1, arr2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
