#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (j >= i && arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[j]);

    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {4, 7, 3, 8, 2, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:";
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "\nSorted array:";
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }

    return 0;
}
