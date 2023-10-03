// You are using GCC
#include <iostream>
#include <deque>
#include <climits>

using namespace std;

int main() {
    deque<int> stockPrices;
    int price;

    while (true) {
        cin >> price;

        if (price == -1) {
            break; 
        }

        stockPrices.push_back(price); 
    }

    if (stockPrices.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        int minPrice = INT_MAX;
        for (int p : stockPrices) {
            if (p < minPrice) {
                minPrice = p;
            }
        }
        cout << minPrice << endl;
    }

    return 0;
}
