// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

int main() {
    int n, m;

    cin >> n;
    vector<int> stock(n);
    for (int i = 0; i < n; i++) {
        cin >> stock[i];
    }

    cin >> m;
    vector<int> cart(m);
    for (int i = 0; i < m; i++) {
        cin >> cart[i];
    }

    vector<int> mergedArray;
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (stock[i] < cart[j]) {
            mergedArray.push_back(stock[i]);
            i++;
        } else if (stock[i] > cart[j]) {
            mergedArray.push_back(cart[j]);
            j++;
        } else {
            mergedArray.push_back(stock[i]);
            i++;
            j++;
        }
    }

    while (i < n) {
        mergedArray.push_back(stock[i]);
        i++;
    }
    while (j < m) {
        mergedArray.push_back(cart[j]);
        j++;
    }

    for (int k = 0; k < mergedArray.size(); k++) {
        cout << mergedArray[k];
        if (k < mergedArray.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
