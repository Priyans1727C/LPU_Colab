#include <iostream>
class add
{
   protected:
        int x;
};
int main() {
    int initialAmount;
    std::cin >> initialAmount;
    int totalAmount = initialAmount + 50;

    std::cout << totalAmount << std::endl;

    return 0;
}
