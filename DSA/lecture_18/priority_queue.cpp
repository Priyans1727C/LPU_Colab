// You are using GCC
#include <iostream>
#include <vector>

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    std::vector<int> elements;
    std::vector<int> priorities;
    int size;

public:
    PriorityQueue() {
        elements.resize(MAX_SIZE);
        priorities.resize(MAX_SIZE);
        size = 0;
    }

    void enqueue(int element, int priority) {
        if (isFull()) {
            std::cout << "Priority Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        int index = size;
        while (index > 0 && priority < priorities[index - 1]) {
            elements[index] = elements[index - 1];
            priorities[index] = priorities[index - 1];
            index--;
        }

        elements[index] = element;
        priorities[index] = priority;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a placeholder value for an empty queue
        }

        int highestPriorityIndex = 0;
        for (int i = 1; i < size; i++) {
            if (priorities[i] < priorities[highestPriorityIndex]) {
                highestPriorityIndex = i;
            }
        }

        int item = elements[highestPriorityIndex];

        for (int i = highestPriorityIndex; i < size - 1; i++) {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }

        size--;
        return item;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void printPriorityQueue() {
        
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue pq;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int element, priority;
        std::cin >> element >> priority;
        pq.enqueue(element, priority);
    }

    std::cout << "Priority Queue: ";
    pq.printPriorityQueue();

    int dequeued = pq.dequeue();
    std::cout << "Priority Queue: ";
    pq.printPriorityQueue();

    return 0;
}
