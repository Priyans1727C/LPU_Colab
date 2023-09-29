// You are using GCC
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(const string& task) {
        data = task;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(const string& task) {
        Node* newNode = new Node(task);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string getFrontTask() {
        if (front == nullptr) {
            return "No tasks in the queue";
        }
        return front->data;
    }

    string getRearTask() {
        if (rear == nullptr) {
            return "No tasks in the queue";
        }
        return rear->data;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character

    Queue taskQueue;

    for (int i = 0; i < n; i++) {
        string task;
        getline(cin, task);
        taskQueue.enqueue(task);
    }

    cout << "Front Task: " << taskQueue.getFrontTask() << endl;
    cout << "Rear Task: " << taskQueue.getRearTask() << endl;

    return 0;
}
