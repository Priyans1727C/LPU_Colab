#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= 99) {
            cout << "Stack Overflow. Cannot push more elements." << endl;
        } else {
            arr[++top] = value;
            cout << "Element " << value << " pushed onto the stack." << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow. Cannot perform pop operation." << endl;
        } else {
            cout << "Element " << arr[top--] << " popped from the stack." << endl;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Elements in the stack:";
            for (int i = top; i >= 0; i--) {
                cout << " " << arr[i];
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice;

    do {

        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
