#include <iostream>

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    return count;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (countOnes(arr[j]) < countOnes(pivot) || (countOnes(arr[j]) == countOnes(pivot) && arr[j] < pivot)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    std::cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
