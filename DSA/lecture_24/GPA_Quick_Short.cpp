#include <iostream>
#include <iomanip>  

void quickSort(float arr[], int low, int high);

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    std::cin >> N;
    float arr[N];

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cout << std::fixed << std::setprecision(1) << arr[i] << " ";
    }

    return 0;
}
