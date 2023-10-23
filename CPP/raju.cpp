#include <iostream>
#include <cstring>

char* reverseString(const char* input) {
    int len = strlen(input);
    char* reversed = new char[len + 1];

    for (int i = 0; i < len; i++) {
        reversed[i] = input[len - i - 1];
    }

    reversed[len] = '\0';
    return reversed;
}

int main() {
    char input[1001];
    std::cin.getline(input, 1001);

    char* reversed = reverseString(input);

    std::cout << "Reversed string: " << reversed << std::endl;

    delete[] reversed; // Deallocate the dynamically allocated memory

    return 0;
}
