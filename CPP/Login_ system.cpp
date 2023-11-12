#include <iostream>
#include <string>

int main() {
    try {
        std::string username, password;

        // Input username
        std::getline(std::cin, username);

        // Input password
        std::getline(std::cin, password);

        // Check password requirements
        if (password.length() < 6) {
            throw "Password must be at least 6 characters long";
        }

        bool hasDigit = false;
        for (char ch : password) {
            if (isdigit(ch)) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit) {
            throw "Password must have at least one digit";
        }

        std::cout << "Password is Correct" << std::endl;
    } catch (const char* msg) {
        std::cout << msg << std::endl;
        std::cout << "Caught by Exception" << std::endl;
        std::cout << "Invalid Password Format!" << std::endl;
    }

    return 0;
}
