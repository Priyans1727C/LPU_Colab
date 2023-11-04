
#include <iostream>
using namespace std;

struct RideRequest {
    int estimatedPickUpTime;
};

void swap(RideRequest& a, RideRequest& b) {
    RideRequest temp = a;
    a = b;
    b = temp;
}

// Function to insert a new ride request into the min heap based on estimated pick-up time
void insertRideRequest(RideRequest heap[], int& heapSize, RideRequest newRequest) {
    heapSize++;

    int i = heapSize - 1;
    heap[i] = newRequest;

    while (i > 0 && heap[(i - 1) / 2].estimatedPickUpTime > heap[i].estimatedPickUpTime) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(RideRequest heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].estimatedPickUpTime << " ";
    }
    cout << endl;
}

int main() {
    RideRequest minHeap[100];
    int heapSize = 0;

    while (true) {
        RideRequest newRequest;
        if (!(cin >> newRequest.estimatedPickUpTime)) {
            break;
        }

        insertRideRequest(minHeap, heapSize, newRequest);
    }
    printHeap(minHeap, heapSize);

    return 0;
}
