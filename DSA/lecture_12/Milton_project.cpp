// You are using GCC
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            head->next = head;  
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = head;
        }
    }

    bool isSorted() {
        if (head == nullptr) {
            return true;  
        }

        Node* current = head;
        do {
            if (current->data > current->next->data) {
                return false;
            }
            current = current->next;
        } while (current->next != head);

        return true;
    }
};

int main() {
    int n;
    std::cin >> n;

    CircularLinkedList circularLinkedList;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        circularLinkedList.append(data);
    }

    if (circularLinkedList.isSorted()) {
        std::cout << "The list is sorted in non-decreasing order." << std::endl;
    } else {
        std::cout << "The list is not sorted in non-decreasing order." << std::endl;
    }

    return 0;
}
