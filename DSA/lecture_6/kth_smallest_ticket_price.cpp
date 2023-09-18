#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& prices) {
    int n = prices.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (prices[j] < prices[minIndex]) {
                minIndex = j;
            }
        }
       
        int temp = prices[i];
        prices[i] = prices[minIndex];
        prices[minIndex] = temp;
    }
}

int main() {
    int n, k;
    cin >> n;

    vector<int> ticketPrices(n);

   
    for (int i = 0; i < n; i++) {
        cin >> ticketPrices[i];
    }

    cin >> k;


    selectionSort(ticketPrices);

 
    cout << "Sorted order: ";
    for (int i = 0; i < n; i++) {
        cout << ticketPrices[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

   
    cout << "The kth smallest element is: " << ticketPrices[k - 1] << endl;

    return 0;
}
