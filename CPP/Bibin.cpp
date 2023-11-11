#include <iostream>
#include <stdexcept>

class NegativeRadiusException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Radius cannot be negative or zero.";
    }
};

class Circle {
private:
    double radius;

public:
    Circle() : radius(0) {}

    void setRadius(double r) {
        if (r <= 0) {
            throw NegativeRadiusException();
        }

        radius = r;
        std::cout << "Radius set successfully: " << radius << std::endl;
    }

    double getRadius() const {
        return radius;
    }
};

int main() {
    Circle circle;
    double inputRadius;

    try {
        std::cin >> inputRadius;
        circle.setRadius(inputRadius);
    } catch (const NegativeRadiusException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
    }

    return 0;
}
