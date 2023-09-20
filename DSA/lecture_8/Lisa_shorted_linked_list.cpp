// You are using GCC
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
public:
    Node* head;

    SortedLinkedList() : head(nullptr) {}

    void insertSorted(int val) {
        Node* newNode = new Node(val);

        if (!head || val <= head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && val > current->next->data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    SortedLinkedList list;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insertSorted(val);
    }

    int newVal;
    cin >> newVal;

    list.insertSorted(newVal);
    list.printList();

    return 0;
}
