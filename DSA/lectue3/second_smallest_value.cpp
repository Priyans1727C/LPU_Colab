#include <iostream>
using namespace std;

int main() {
    int size1, size2;
    cin >> size1;

    int arr1[100], arr2[100];

    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cin >> size2;

    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    cout << "Common Elements: ";

    bool found = false;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                found = true;
                break; // Exit the inner loop once a common element is found
            }
        }
    }

    if (!found) {
        cout << "None";
    }

    cout << endl;

    return 0;
}
