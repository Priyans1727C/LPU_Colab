#include <iostream>

using namespace std;

class Parent {
public:
    int num;
};

class Child : public Parent {
public:
    void fun() {
        int sum = 0;
        int n = to_string(num).length();
        int digits[n];

        for (int i = 0; i < n; i++) {
            digits[i] = num % 10;
            num /= 10;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += digits[i] + digits[j];
            }
        }

        cout << sum << endl;
    }
};

int main() {
    int input;
    cin >> input;

    Child c;
    c.num = input;
    c.fun();

    return 0;
}
