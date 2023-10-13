#include <iostream>

int main() {
    int hours, minutes;
    std::cin >> hours >> minutes;

    int totalMinutes = hours * 60 + minutes;

    std::cout << totalMinutes << " mins" << std::endl;

    return 0;
}
