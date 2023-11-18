#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int tableSize = 10;
    int numDishes;
    scanf("%d", &numDishes);
    int prices[numDishes];
    for (int i = 0; i < numDishes; i++) {
        scanf("%d", &prices[i]);
    }

    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numDishes; i++) {
        int hashIndex = prices[i] % tableSize;
        int j = 1;
        while (hashTable[hashIndex] != -1) {
            // Quadratic probing to find the next available slot
            hashIndex = (hashIndex + j * j) % tableSize;
            j++;
        }
        hashTable[hashIndex] = prices[i];
    }

    int primeFound = 0;
    for (int i = 2; i < tableSize; i++) {
        if (isPrime(i) && hashTable[i] != -1) {
            printf("The price of the dish in prime position: %d is Rs.%d\n", i, hashTable[i]);
            primeFound = 1;
        }
    }

    if (!primeFound) {
        printf("No dish is placed in prime position\n");
    }

    return 0;
}
