#include <iostream>

const int MAX_Char_Length = 30;

void merge(char arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char leftArr[MAX_Char_Length];
    char rightArr[MAX_Char_Length];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(char arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;
    char characters[MAX_Char_Length];

    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    mergeSort(characters, 0, n - 1);

    // Print the sorted characters
    std::cout << "Sorted Characters:";
    for (int i = 0; i < n; ++i) {
        std::cout << ' ' << characters[i];
    }
    std::cout << std::endl;

    return 0;
}
