// You are using GCC
#include <iostream>
using namespace std;

void rearrangeNegativesBeforePositives(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Find the first positive number from the left
        while (low <= high && arr[low] < 0) {
            low++;
        }

        // Find the first negative number from the right
        while (low <= high && arr[high] >= 0) {
            high--;
        }

        if (low <= high) {
            // Swap the positive and negative numbers
            std::swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrangeNegativesBeforePositives(arr, n);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
