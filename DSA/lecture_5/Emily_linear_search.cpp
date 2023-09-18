// You are using GCC
#include <iostream>
#include <string>

using namespace std;

int countWords(const string& str) {
    int wordCount = 0;
    bool inWord = false;

    for (char c : str) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    string input;
    getline(cin, input);

    int wordCount = countWords(input);
    cout << wordCount << endl;

    return 0;
}
