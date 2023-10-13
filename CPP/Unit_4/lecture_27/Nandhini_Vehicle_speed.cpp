#include <iostream>

 class Vehicle
 {
    public: 
            class Car{};
};
int main() {
    double distance, time;
    std::cin >> distance >> time;
    if (time == 0) {
        std::cerr << "Error: Time cannot be zero." << std::endl;
        return 1;
    }
    double speed = distance / time;
    std::cout << "Speed of car: "  speedKmph << " km/hr" << std::endl;

    return 0;
}
