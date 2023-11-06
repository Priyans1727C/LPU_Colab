
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root) {
    int largest = root; // Initialize the largest as the root
    int left = 2 * root + 1; // Index of the left child
    int right = 2 * root + 2; // Index of the right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != root) {
        swap(arr[root], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Build a max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    // Build a max heap
    buildMaxHeap(arr, n);

    // Perform heap sort
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    heapSort(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}
