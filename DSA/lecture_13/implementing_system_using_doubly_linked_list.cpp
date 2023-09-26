// You are using GCC
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList scoreList;

    int score;
    while (cin >> score) {
        scoreList.insertAtFront(score);
        cout << "Node Inserted" << endl;
        scoreList.display();
    }

    return 0;
}
