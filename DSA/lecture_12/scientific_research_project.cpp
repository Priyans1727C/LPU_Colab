// You are using GCC
#include <iostream>

class Node {
public:
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtEnd(float val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head;
        Node* temp;

        do {
            temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
};

int main() {
    int n;
    std::cin >> n;

    CircularLinkedList linkedList;

    for (int i = 0; i < n; i++) {
        float val;
        std::cin >> val;
        linkedList.insertAtEnd(val);
    }

    linkedList.display();

    return 0;
}
