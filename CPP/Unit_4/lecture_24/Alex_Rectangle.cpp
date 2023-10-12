#include <iostream>
#include <vector>
#include <iomanip>

struct Rectangle {
    double length;
    double width;

    double getPerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Rectangle> rectangles(n);

    for (int i = 0; i < n; i++) {
        std::cin >> rectangles[i].length >> rectangles[i].width;
    }

    double smallestPerimeter = rectangles[0].getPerimeter();

    for (int i = 0; i < n; i++) {
        double perimeter = rectangles[i].getPerimeter();
        std::cout << "Perimeter of rectangle " << (i + 1) << ": " << perimeter << std::endl;
        if (perimeter < smallestPerimeter) {
            smallestPerimeter = perimeter;
        }
    }

    std::cout << "Perimeter of the smallest rectangle: " << smallestPerimeter << std::endl;

    return 0;
}
