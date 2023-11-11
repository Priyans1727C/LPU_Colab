#include <iostream>
#include <stdexcept>

int main() {
    try {
        double initialBalance, withdrawAmount;
        std::cin >> initialBalance >> withdrawAmount;

        if (withdrawAmount <= initialBalance) {
            // Successful withdrawal
            std::cout << "Withdrawal successful." << std::endl;
            std::cout << "New balance: " << initialBalance - withdrawAmount << std::endl;
        } else {
            // Insufficient funds exception
            throw std::underflow_error("Insufficient money for withdrawal.");
        }
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught." << std::endl;
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
