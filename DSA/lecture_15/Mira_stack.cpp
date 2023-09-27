// You are using GCC
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;
    
    while (true) {
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                int val;
                cin >> val;
                myStack.push(val);
                break;
            case 2:
                if (!myStack.empty()) {
                    myStack.pop();
                } else {
                    cout << "Stack is empty. Cannot perform pop operation." << endl;
                }
                break;
            case 3:
                if (!myStack.empty()) {
                    stack<int> tempStack = myStack;
                    cout << "Elements in the stack:";
                    while (!tempStack.empty()) {
                        cout << " " << tempStack.top();
                        tempStack.pop();
                    }
                    cout << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    
    return 0;
}
