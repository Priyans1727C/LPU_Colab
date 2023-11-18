#include <stdio.h>
#define TABLE_SIZE 100

int hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int midSquareHash(int key) {
    int square = key * key;
    int middleDigits = (square / 10) % 100;
    return middleDigits % TABLE_SIZE;
}

int linearProbe(int index) {
    int newIndex = index;
    while (hashTable[newIndex] != -1) {
        newIndex = (newIndex + 1) % TABLE_SIZE;
    }
    return newIndex;
}

int main() {
    initializeHashTable();
    int n, key;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        int index = midSquareHash(key);

        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            int newIndex = linearProbe(index);
            hashTable[newIndex] = key;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: Key %d\n", i, hashTable[i]);
        }
    }

    return 0;
}
