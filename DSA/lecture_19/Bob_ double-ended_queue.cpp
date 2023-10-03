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

    int count = myDeque.size();

    cout << "Number of elements in the deque: " << count << endl;

    return 0;
}
