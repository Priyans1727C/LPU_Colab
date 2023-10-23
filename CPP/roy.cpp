#include <iostream>

void generateFibonacci(int n) {
    if (n < 1) {
        std::cout << "Number of Fibonacci numbers should be positive!" << std::endl;
        return;
    }

    int* fibonacci = new int[n];

    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
    }

    std::cout << "Fibonacci Sequence: ";
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    for (int i = 0; i < n; i++) {
        std::cout << fibonacci[i] << " ";
    }
    std::cout << std::endl;

    delete[] fibonacci; // Deallocate the dynamically allocated memory
}

int main() {
    int n;
    std::cin >> n;

    generateFibonacci(n);

    return 0;
}
