#include <iostream>

using namespace std;

void findDuplicates(int arr[], int n, int currentIndex) {
    if (currentIndex >= n) {
        return;
    }

    int currentElement = arr[currentIndex];

    for (int i = currentIndex + 1; i < n; i++) {
        if (currentElement == arr[i]) {
            cout << currentElement << " ";
            break;
        }
    }

    findDuplicates(arr, n, currentIndex + 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool foundDuplicates = false;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                foundDuplicates = true;
                break;
            }
        }
        if (foundDuplicates) {
            break;
        }
    }

    if (foundDuplicates) {
        findDuplicates(arr, n, 0);
    } else {
        cout << "-1";
    }

    cout << endl;

    return 0;
}
