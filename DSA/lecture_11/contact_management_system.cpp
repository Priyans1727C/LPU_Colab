#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        insertAtEnd(head, element);
    }

    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
