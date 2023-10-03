// You are using GCC
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque;
    int num;

    while (true) {
        cin >> num;

        if (num == -1) {
            break; 
        }

        myDeque.push_back(num); 
    }

    if (myDeque.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        int maxElement = myDeque.front();
        for (int element : myDeque) {
            if (element > maxElement) {
                maxElement = element;
            }
        }
        cout << maxElement << endl;
    }

    return 0;
}
