#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& playlist, int target) {
    int left = 0;
    int right = playlist.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (playlist[mid] == target) {
            return mid;
        } else if (playlist[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int n;
    cin >> n;
    vector<int> playlist(n);

    for (int i = 0; i < n; i++) {
        cin >> playlist[i];
    }

    int target;
    cin >> target;

    int result = binarySearch(playlist, target);
    cout << result << endl;

    return 0;
}
