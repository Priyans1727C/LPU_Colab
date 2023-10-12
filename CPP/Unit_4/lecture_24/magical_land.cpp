#include <iostream>
#include <map>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::map<std::string, int> wordCounts;
    std::vector<std::string> wordOrder;

    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        wordCounts[word]++;
        
        if (wordCounts[word] == 1) {
            wordOrder.push_back(word);
        }
    }

    int totalWords = wordOrder.size();

    std::cout << "Total words: " << totalWords << std::endl;
    std::cout << "Word Counts:" << std::endl;

    for (const std::string& word : wordOrder) {
        std::cout << word << ": " << wordCounts[word] << std::endl;
    }

    return 0;
}
