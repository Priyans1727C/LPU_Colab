// You are using GCC
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(const string& val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtEnd(const string& val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void splitIntoHalves(DoublyLinkedList& firstHalf, DoublyLinkedList& secondHalf) {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

       
        firstHalf.head = head;
        firstHalf.tail = slow;
        firstHalf.size = size / 2;

        secondHalf.head = slow->next;
        secondHalf.tail = tail;
        secondHalf.size = size - (size / 2);

       
        slow->next = nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList studentDatabase;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        studentDatabase.insertAtEnd(name);
    }

    DoublyLinkedList firstHalf;
    DoublyLinkedList secondHalf;

    studentDatabase.splitIntoHalves(firstHalf, secondHalf);

    firstHalf.display();
    cout << endl;

    secondHalf.display();
    cout << endl;

    return 0;
}
