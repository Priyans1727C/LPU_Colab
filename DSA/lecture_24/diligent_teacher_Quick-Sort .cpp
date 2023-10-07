#include <iostream>

using namespace std;

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    float marks[N];

    for (int i = 0; i < N; i++) {
        cin >> marks[i];
    }

    quickSort(marks, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << marks[i] << " ";
    }

    return 0;
}
