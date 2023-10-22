#include <iostream>
#include <cmath>

using namespace std;

class CurrentBill {
public:
    virtual double amount() = 0;
};

class Fan : public CurrentBill {
private:
    int powerConsumption;
    int usageHours;

public:
    Fan(int power, int hours) : powerConsumption(power), usageHours(hours) {}

    double amount() override {
        return (powerConsumption * usageHours) / 1000.0; // Bill calculation formula
    }
};

class Light : public CurrentBill {
private:
    int powerConsumption;
    int usageHours;

public:
    Light(int power, int hours) : powerConsumption(power), usageHours(hours) {}

    double amount() override {
        return (powerConsumption * usageHours) / 1000.0; // Bill calculation formula
    }
};

class TV : public CurrentBill {
private:
    int powerConsumption;
    int usageHours;

public:
    TV(int power, int hours) : powerConsumption(power), usageHours(hours) {}

    double amount() override {
        return (powerConsumption * usageHours) / 1000.0; // Bill calculation formula
    }
};

int main() {
    int fanPower, fanHours, lightPower, lightHours, tvPower, tvHours;

    cin >> fanPower >> fanHours;
    cin >> lightPower >> lightHours;
    cin >> tvPower >> tvHours;

    Fan fan(fanPower, fanHours);
    Light light(lightPower, lightHours);
    TV tv(tvPower, tvHours);

    double totalBill = fan.amount() + light.amount() + tv.amount();

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << totalBill << endl;

    return 0;
}
