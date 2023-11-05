
#include <stdio.h>
#include <stdlib.h>

struct Task {
    int urgency;
};

void swap(struct Task* a, struct Task* b) {
    struct Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new task into the binary heap based on urgency
void insertTask(struct Task heap[], int* heapSize, struct Task newTask) {
    int i = *heapSize;
    heap[i] = newTask;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2].urgency < heap[i].urgency) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(struct Task heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].urgency > heap[largest].urgency) {
        largest = left;
    }

    if (right < size && heap[right].urgency > heap[largest].urgency) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(struct Task heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

void printHeap(struct Task heap[], int heapSize) {
    buildMaxHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].urgency);
    }
    printf("\n");
}

int main() {
    struct Task taskHeap[100];
    int heapSize = 0;

    while (1) {
        struct Task newTask;
        if (scanf("%d", &newTask.urgency) != 1 || newTask.urgency == -1) {
            break;
        }
        insertTask(taskHeap, &heapSize, newTask);
    }

    printHeap(taskHeap, heapSize);

    return 0;
}
