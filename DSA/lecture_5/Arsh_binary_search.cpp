#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target, k;
    cin >> target >> k;

    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    left--;
    right = left + 1;

    auto compare = [&](int a, int b) {
        return abs(a - target) < abs(b - target);
    };

    vector<int> closest;

    while (k > 0) {
        if (left >= 0 && (right >= n || compare(arr[left], arr[right]))) {
            closest.push_back(arr[left]);
            left--;
        } else {
            closest.push_back(arr[right]);
            right++;
        }
        k--;
    }

    // Print the k closest elements
    for (int i = 0; i < closest.size(); i++) {
        cout << closest[i] << " ";
    }

    return 0;
}
