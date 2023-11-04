
#include <stdio.h>
#include <stdlib.h>

struct Task {
    int priority;
};

void swap(struct Task* a, struct Task* b) {
    struct Task temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Task heap[], int i, int heapSize) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].priority < heap[smallest].priority)
        smallest = left;

    if (right < heapSize && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}

void insertTaskPriority(struct Task heap[], int* heapSize, struct Task newTask) {
    if (*heapSize == 100) {
        printf("Min heap is full. Cannot insert more tasks.\n");
        return;
    }

    int i = (*heapSize)++;
    heap[i] = newTask;

    while (i != 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct Task heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        if (i == heapSize - 1) {
            printf("%d", heap[i].priority);
        } else {
            printf("%d ", heap[i].priority);
        }
    }
    printf("\n");
}

int main() {
    struct Task minHeap[100];
    int heapSize = 0;

    while (1) {
        struct Task newTask;
        if (scanf("%d", &newTask.priority) != 1) {
            break;
        }
        insertTaskPriority(minHeap, &heapSize, newTask);
    }

    printHeap(minHeap, heapSize);

    return 0;
}
