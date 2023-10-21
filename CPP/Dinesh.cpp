#include <iostream>
#include <iomanip>

using namespace std;

class ItemType {
public:
    virtual double calculateAmount() {
        return 0.0;
    }
};

class Wooden : public ItemType {
private:
    int noOfItems;
    double cost;

public:
    Wooden(int items, double itemCost) : noOfItems(items), cost(itemCost) {}

    double calculateAmount() override {
        return noOfItems * cost;
    }
};

class Electronics : public ItemType {
private:
    double cost;

public:
    Electronics(double itemCost) : cost(itemCost) {}

    double calculateAmount() override {
        return cost * 0.8; // 20% discount
    }
};

int main() {
    int choice;
    cin >> choice;

    if (choice == 1) {
        int noOfItems;
        double itemCost;
        cin >> noOfItems >> itemCost;
        Wooden woodenItem(noOfItems, itemCost);
        cout << fixed << setprecision(2) << woodenItem.calculateAmount() << endl;
    } else if (choice == 2) {
        double itemCost;
        cin >> itemCost;
        Electronics electronicItem(itemCost);
        cout << fixed << setprecision(2) << electronicItem.calculateAmount() << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
