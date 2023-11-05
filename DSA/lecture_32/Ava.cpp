
#include <stdio.h>
#include <stdlib.h>

struct Job {
    int processing_time;
};

void swap(struct Job* a, struct Job* b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new job into the binary max-heap based on processing time
void insertJob(struct Job heap[], int* heapSize, struct Job newJob) {
    int i = *heapSize;
    heap[i] = newJob;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2].processing_time < heap[i].processing_time) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(struct Job heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].processing_time > heap[largest].processing_time) {
        largest = left;
    }

    if (right < size && heap[right].processing_time > heap[largest].processing_time) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(struct Job heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

void printHeap(struct Job heap[], int heapSize) {
    buildMaxHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].processing_time);
    }
    printf("\n");
}

int main() {
    struct Job jobHeap[100];
    int heapSize = 0;

    while (1) {
        struct Job newJob;
        if (scanf("%d", &newJob.processing_time) != 1) {
            break;
        }
        insertJob(jobHeap, &heapSize, newJob);
    }

    printHeap(jobHeap, heapSize);

    return 0;
}
