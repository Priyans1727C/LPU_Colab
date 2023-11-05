#include <stdio.h>
#include <stdlib.h>

struct Message {
    char content;
};

void swap(struct Message* a, struct Message* b) {
    struct Message temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new message into the max heap
void insertMessage(struct Message heap[], int* heapSize, struct Message newMessage) {
    int i = *heapSize;
    heap[i] = newMessage;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2].content < heap[i].content) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(struct Message heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].content > heap[largest].content) {
        largest = left;
    }

    if (right < size&& heap[right].content > heap[largest].content) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(struct Message heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

void printHeap(struct Message heap[], int heapSize) {
    buildMaxHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        printf("%c ", heap[i].content);
    }
    printf("\n");
}

int main() {
    struct Message maxHeap[100];
    int heapSize = 0;

    while (1) {
        struct Message newMessage;
        if (scanf(" %c", &newMessage.content) != 1) {
            break;
        }
        insertMessage(maxHeap, &heapSize, newMessage);
    }

    printHeap(maxHeap, heapSize);

    return 0;
}
