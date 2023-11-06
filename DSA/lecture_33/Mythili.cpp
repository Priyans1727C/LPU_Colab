
#include <stdio.h>

void MaxHeapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        MaxHeapify(arr, N, largest);
    }
}

void MaxHeapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        MaxHeapify(arr, i, 0);
    }
}

void MinHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        MinHeapify(arr, n, smallest);
    }
}

void MinHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        MinHeapify(arr, i, 0);
    }
}

void printHeapArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 2) {
        printf("Invalid choice");
        return 0;
    }

    if (choice == 1) {
        MaxHeapSort(arr, n);
    } else if (choice == 2) {
        MinHeapSort(arr, n);
    }

    printHeapArray(arr, n);
    return 0;
}
