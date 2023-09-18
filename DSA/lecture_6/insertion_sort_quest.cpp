#include <iostream>
#include <vector>
#include <string>

using namespace std;

void insertionSort(vector<string>& contacts) {
    int n = contacts.size();
    for (int i = 1; i < n; i++) {
        string key = contacts[i];
        int j = i - 1;

 
        while (j >= 0 && contacts[j] > key) {
            contacts[j + 1] = contacts[j];
            j = j - 1;
        }
        contacts[j + 1] = key;

        cout << "After Iteration " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << contacts[k];
            if (k != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> contacts(n);

    for (int i = 0; i < n; i++) {
        cin >> contacts[i];
    }

    cout << "Initial order: ";
    for (int i = 0; i < n; i++) {
        cout << contacts[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    insertionSort(contacts);

    cout << "Sorted order: ";
    for (int i = 0; i < n; i++) {
        cout << contacts[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
