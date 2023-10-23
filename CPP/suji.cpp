#include <iostream>

void reverseArray(int* arr, int size) {
    int* reversedArr = new int[size];

    // Reversing the array
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }

    std::cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << reversedArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] reversedArr;
}

int main() {
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Size of the array should be positive" << std::endl;
        return 1;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    reverseArray(arr, size);

    delete[] arr; // Deallocate the dynamically allocated memory

    return 0;
}
