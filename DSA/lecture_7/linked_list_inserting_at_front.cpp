// You are using GCC
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
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

    LinkedList list;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insertFront(val);
    }

    int frontVal;
    cin >> frontVal;

    cout << "Created Linked list: ";
    list.printList();

    list.insertFront(frontVal);

    cout << "Final List: ";
    list.printList();

    return 0;
}
