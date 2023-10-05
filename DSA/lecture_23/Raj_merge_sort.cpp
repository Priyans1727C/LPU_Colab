#include <iostream>
#include <vector>

const int max_n = 100;

void merge(std::vector<int> &arr, std::vector<int> &freq, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (freq[leftArr[i]] < freq[rightArr[j]] || (freq[leftArr[i]] == freq[rightArr[j]] && leftArr[i] < rightArr[j])) {
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

void mergeSort(std::vector<int> &arr, std::vector<int> &freq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, freq, left, mid);
        mergeSort(arr, freq, mid + 1, right);

        merge(arr, freq, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(max_n + 1, 0);
    std::vector<int> freq(max_n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        arr[i] = num;
        freq[num]++;
    }

    mergeSort(arr, freq, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
