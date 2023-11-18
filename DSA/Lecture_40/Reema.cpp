#include <stdio.h>

int midSquareHash(int key, int tableSize) {
    int squared = key * key;
    int middleDigit = (squared / 10) % 10;
    return middleDigit % tableSize;
}

int main() {
    int tableSize = 100;
    int numKeys;
    scanf("%d", &numKeys);
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }

    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numKeys; i++) {
        int index = midSquareHash(keys[i], tableSize);

        while (hashTable[index] != -1) {
            // Linear probing to find the next available slot
            index = (index + 1) % tableSize;
        }

        // Store the key in the hash table
        hashTable[index] = keys[i];
    }

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: Key %d\n", i, hashTable[i]);
        }
    }

    return 0;
}
