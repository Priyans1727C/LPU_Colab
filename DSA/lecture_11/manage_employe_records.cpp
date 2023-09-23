// You are using GCC
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    std::pair<Node*, Node*> splitEvenOdd() {
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
        Node* current = head;

        while (current) {
            if (current->data % 2 == 0) {
                if (!evenHead) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = evenTail->next;
                }
            } else {
                if (!oddHead) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = oddTail->next;
                }
            }
            current = current->next;
        }

        if (evenTail) {
            evenTail->next = nullptr;
        }
        if (oddTail) {
            oddTail->next = nullptr;
        }

        return std::make_pair(evenHead, oddHead);
    }

    void printList(Node* head, const std::string& label) {
        std::cout << label << ": ";
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    LinkedList linkedList;
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        linkedList.append(data);
    }

    std::pair<Node*, Node*> result = linkedList.splitEvenOdd();

    linkedList.printList(result.first, "Even List");
    linkedList.printList(result.second, "Odd List");

    return 0;
}
