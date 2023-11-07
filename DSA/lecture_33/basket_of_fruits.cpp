
#include <iostream>
using namespace std;

struct Fruit {
    int sweetness;
};

void swap(Fruit& x, Fruit& y) {
    Fruit temp = x;
    x = y;
    y = temp;
}

void heapifyDown(Fruit* heap, int n, int i) {
    int sweetest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].sweetness > heap[sweetest].sweetness)
        sweetest = left;

    if (right < n && heap[right].sweetness > heap[sweetest].sweetness)
        sweetest = right;

    if (sweetest != i) {
        swap(heap[i], heap[sweetest]);
        heapifyDown(heap, n, sweetest);
    }
}

Fruit removeSweetestFruit(Fruit* heap, int& n) {
    Fruit sweetestFruit = heap[0];
    if (n <= 0) {
        return sweetestFruit; // Nothing to delete
    }

    // Replace the root with the last element
    heap[0] = heap[n - 1];
    n--;

    // Heapify down to maintain the max-heap property
    heapifyDown(heap, n, 0);

    return sweetestFruit;
}

int main() {
    Fruit* basket;
    int n;
    cin >> n;
    basket = new Fruit[n];
    for (int i = 0; i < n; i++) {
        cin >> basket[i].sweetness;
    }

    // Ensure the max-heap property
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(basket, n, i);
    }

    Fruit eatenFruit = removeSweetestFruit(basket, n);
    cout << eatenFruit.sweetness << endl;
    delete[] basket;
    return 0;
}
