
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, double> findMedian(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    sort(merged.begin(), merged.end());

    int n = merged.size();
    double median;
    
    if (n % 2 == 0) {
        int mid1 = merged[n / 2 - 1];
        int mid2 = merged[n / 2];
        median = (mid1 + mid2) / 2.0;
    } else {
        median = merged[n / 2];
    }
    
    return make_pair(merged, median);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }

    auto result = findMedian(arr1, arr2);
    vector<int> merged_array = result.first;
    double median_value = result.second;

    cout << median_value << endl;

    return 0;
}
