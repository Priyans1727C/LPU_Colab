#include <iostream>
#include <unordered_set>

void findPairsWithSum(int* arr, int size, int targetSum) {
    std::unordered_set<int> seen;
    bool found = false;

    std::cout << "Pairs with the sum " << targetSum << " are:" << std::endl;
    for (int i = 0; i < size; i++) {
        int complement = targetSum - arr[i];

        if (seen.find(complement) != seen.end()) {
            found = true;
            std::cout << "Pair found: (" << arr[i] << ", " << complement << ")" << std::endl;
        }

        seen.insert(arr[i]);
    }

    if (!found) {
        std::cout << "No pair" << std::endl;
    }
}

int main() {
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Size of the array should be positive!" << std::endl;
        return 1;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int targetSum;
    std::cin >> targetSum;

    findPairsWithSum(arr, size, targetSum);

    delete[] arr;  // Deallocate the dynamically allocated memory

    return 0;
}
