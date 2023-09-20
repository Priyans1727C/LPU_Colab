// You are using GCC
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
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

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int calculateDecimalValue(LinkedList list) {
    int decimalValue = 0;
    Node* current = list.head;

    while (current) {
        decimalValue = (decimalValue << 1) | current->data;
        current = current->next;
    }

    return decimalValue;
}

int main() {
    int n;
    cin >> n;
    LinkedList list;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        list.insert(data);
    }

    cout << "Linked List: ";
    list.display();

    int decimalValue = calculateDecimalValue(list);
    cout << "Decimal Value: " << decimalValue << endl;

    return 0;
}
