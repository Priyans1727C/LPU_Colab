#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::stack<char> charStack;

    for (char c : input) {
        charStack.push(c);
    }

    std::cout << "Reversed string: ";
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
