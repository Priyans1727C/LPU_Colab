#include <iostream>
using namespace std;

int main() {
    int tableSize = 10;
    int numKeys;
    cin >> numKeys;
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        cin >> keys[i];
    }
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int hashIndex = key % tableSize;
        int j = 0;
        while (hashTable[hashIndex] != -1) {
            j++;
            hashIndex = (hashIndex + j * j) % tableSize;
        }
        hashTable[hashIndex] = key;
    }
    int max = hashTable[0];
    int in = 0;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1 && max < hashTable[i]) {
            max = hashTable[i];
            in = i;
        }
    }
    cout << "The lorry that has high load capacity is in index " << in << ".";
    return 0;
}
