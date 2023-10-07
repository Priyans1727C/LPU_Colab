#include <iostream>

using namespace std;

void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    char characters[N];

    for (int i = 0; i < N; i++) {
        cin >> characters[i];
    }

    quickSort(characters, 0, N - 1);

    printArray(characters, N);

    return 0;
}
