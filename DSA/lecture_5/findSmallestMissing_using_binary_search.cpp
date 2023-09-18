#include <iostream>
#include <vector>

using namespace std;

int findSmallestMissing(vector<int>& priorities, int x) {
    int left = 0;
    int right = priorities.size() - 1;
    int result = x + 1;

    while ((left < right) || (left == right)) {
        int mid = left + (right - left) / 2;

        if ((priorities[mid] == x) || (priorities[mid] > x)) {
            result = priorities[mid] + 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> priorities(n);

    for (int i = 0; i < n; i++) {
        cin >> priorities[i];
    }

    int x;
    cin >> x;

    int smallestMissing = findSmallestMissing(priorities, x);

    cout << "The smallest missing positive integer greater than " << x << " is " << smallestMissing << "." << endl;

    return 0;
}
