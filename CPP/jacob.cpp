#include <iostream>
#include <cmath>

class QuadraticEquation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void solveAndDisplayRoots(bool complexForm = false) {
        double discriminant = b * b - 4 * a * c;
        
        if (discriminant > 0) {
            // Real and distinct roots
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "Root 1: " << root1 << std::endl;
            std::cout << "Root 2: " << root2 << std::endl;
        } else if (discriminant == 0) {
            // Real and equal roots
            double root = -b / (2 * a);
            std::cout << "Root: " << root << std::endl;
        } else {
            // Complex roots
            if (complexForm) {
                double realPart = -b / (2 * a);
                double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
                std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
                std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
            } else {
                std::cout << "No real roots. Roots are complex." << std::endl;
            }
        }
    }
};

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    QuadraticEquation equation(a, b, c);

    equation.solveAndDisplayRoots(true); // Use true to display complex roots

    return 0;
}
