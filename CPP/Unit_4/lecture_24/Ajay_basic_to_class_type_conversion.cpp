#include <iostream>
#include <iomanip>

int main() {
    double kilometers;
    std::cin >> kilometers;

    double miles = kilometers * 0.621371;

    std::cout << "Kilometers: " << std::fixed << std::setprecision(2) << kilometers << " km" << std::endl;
    std::cout << "Miles: " << std::fixed << std::setprecision(2) << miles << " miles" << std::endl;

    return 0;
}
