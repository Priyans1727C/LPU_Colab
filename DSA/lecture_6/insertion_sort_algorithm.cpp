// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

     
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        cout << "After Iteration " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> revenue(n);

    for (int i = 0; i < n; i++) {
        cin >> revenue[i];
    }

    cout << "Initial order: ";
    for (int i = 0; i < n; i++) {
        cout << revenue[i] << " ";
    }
    cout << endl;

    insertionSort(revenue);

    cout << "Sorted order: ";
    for (int i = 0; i < n; i++) {
        cout << revenue[i] << " ";
    }
    cout << endl;

    return 0;
}
