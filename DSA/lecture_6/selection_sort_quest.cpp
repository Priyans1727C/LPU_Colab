#include <iostream>
#include <vector>
#include <string>

using namespace std;

void selectionSort(vector<string>& names) {
    int n = names.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (names[j] < names[minIndex]) {
                minIndex = j;
            }
        }
        
        string temp = names[i];
        names[i] = names[minIndex];
        names[minIndex] = temp;

        
        cout << "After Iteration " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << names[k];
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
    vector<string> names(n);

    
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    
    cout << "Initial order: ";
    for (int i = 0; i < n; i++) {
        cout << names[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    selectionSort(names);

    cout << "Sorted order: ";
    for (int i = 0; i < n; i++) {
        cout << names[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
