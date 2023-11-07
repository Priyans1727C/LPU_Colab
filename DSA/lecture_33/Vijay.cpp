
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void deleteRoot(int arr[], int &n) {
    if (n <= 0) {
        return; // Nothing to delete
    }

    // Replace the root with the last element
    arr[0] = arr[n - 1];
    n--;

    // Heapify down to maintain the max-heap property
    heapify(arr, n, 0);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;
    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);
    deleteRoot(arr, n);
    printArray(arr, n);

    return 0;
}
