
#include <stdio.h>
#include <stdlib.h>

struct Location {
    int distance;
};

void swap(struct Location* a, struct Location* b) {
    struct Location temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Location heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].distance < heap[smallest].distance) {
        smallest = left;
    }

    if (right < size && heap[right].distance < heap[smallest].distance) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(struct Location heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertLocation(struct Location heap[], int* heapSize, struct Location newLocation) {
    int i = *heapSize;
    heap[i] = newLocation;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct Location heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].distance);
    }
    printf("\n");
}

int main() {
    struct Location minHeap[100];
    int heapSize = 0;

    while (1) {
        struct Location newLocation;
        if (scanf("%d", &newLocation.distance) != 1) {
            break;
        }
        insertLocation(minHeap, &heapSize, newLocation);
    }
    buildMinHeap(minHeap, heapSize);
    printHeap(minHeap, heapSize);

    return 0;
}
