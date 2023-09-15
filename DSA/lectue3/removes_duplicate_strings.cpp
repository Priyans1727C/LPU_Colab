
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int size;
    cin >> size;
    cin.ignore();

    string arr[100];

    for (int i = 0; i < size; i++) {
        getline(cin, arr[i]);
    }

    unordered_set<string> uniqueStrings;
    string updatedArray[100];

    int updatedSize = 0;

    for (int i = 0; i < size; i++) {
        if (uniqueStrings.find(arr[i]) == uniqueStrings.end()) {
            uniqueStrings.insert(arr[i]);
            updatedArray[updatedSize] = arr[i];
            updatedSize++;
        }
    }

    cout << "Updated array: ";
    for (int i = 0; i < updatedSize; i++) {
        cout << updatedArray[i];
        if (i < updatedSize - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
