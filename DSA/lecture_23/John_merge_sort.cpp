#include <iostream>

int main() {
    int n;
    std::cin >> n;
    char characters[15];
    char vowels[15];
    char consonants[15];
    int vowelCount = 0;
    int consonantCount = 0;

    // Read the input characters
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    // Separate vowels and consonants
    for (int i = 0; i < n; ++i) {
        char ch = characters[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels[vowelCount++] = ch;
        } else {
            consonants[consonantCount++] = ch;
        }
    }

    // Print the sorted characters
    for (int i = 0; i < vowelCount; ++i) {
        std::cout << vowels[i] << ' ';
    }
    for (int i = 0; i < consonantCount; ++i) {
        std::cout << consonants[i] << ' ';
    }

    return 0;
}
