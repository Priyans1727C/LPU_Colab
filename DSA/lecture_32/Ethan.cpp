
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new task into the max heap
void insertTask(int heap[], int* heapSize, int newTask) {
    int i = *heapSize;
    heap[i] = newTask;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int maxHeap[100];
    int heapSize = 0;

    while (1) {
        int newTask;
        if (scanf("%d", &newTask) != 1) {
            break;
        }
        insertTask(maxHeap, &heapSize, newTask);
    }

    for (int j = 0; j < heapSize; j++) {
        printf("%d ", maxHeap[j]);
    }
    printf("\n");

    return 0;
}
