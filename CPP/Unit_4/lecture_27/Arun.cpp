#include <iostream>
#include <string>

class Parent{};
class Child{};
class BaseSum {
public:
    int calculateSum(int num) {
        std::string numStr = std::to_string(num);
        int totalSum = 0;
        for (int i = 0; i < numStr.length(); i++) {
            for (int j = i + 1; j < numStr.length(); j++) {
                totalSum += (numStr[i] - '0') + (numStr[j] - '0');
            }
        }
        return totalSum;
    }
};

class DerivedSum : public BaseSum {
public:
    int calculateFinalSum(int num) {
        return calculateSum(num);
    }
};

int main() {
    int num;
    std::cin >> num;

    DerivedSum derivedSum;
    int finalSum = derivedSum.calculateFinalSum(num);

    std::cout << finalSum << std::endl;

    return 0;
}
