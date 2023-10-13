#include <iostream>

int main() {
    int initialBalance, withdrawAmount;
    std::cin >> initialBalance >> withdrawAmount;

    if (initialBalance >= withdrawAmount) {
        int updatedBalance = initialBalance - withdrawAmount;
        std::cout << updatedBalance << std::endl;
    } else {
        std::cout << "Insufficient balance" << std::endl;
    }

    return 0;
}
