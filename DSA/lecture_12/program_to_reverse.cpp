#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& message) {
        data = message;
        next = nullptr;
    }
};

class CircularMessageQueue {
public:
    Node* head;

    CircularMessageQueue() {
        head = nullptr;
    }

    void insertMessage(const std::string& message) {
        Node* new_node = new Node(message);
        if (head == nullptr) {
            head = new_node;
            head->next = head;
        } else {
            new_node->next = head->next;
            head->next = new_node;
        }
    }

    void reverseMessages() {
        if (head == nullptr || head->next == head) {
            return;
        }

        Node* current = head->next;
        Node* prev = nullptr;
        Node* next_node;

        do {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        } while (current != head->next);

        head->next = prev;
    }

    void displayMessages() {
        if (head == nullptr) {
            std::cout << "Message queue is empty!" << std::endl;
            return;
        }

        Node* current = head->next;
        std::cout << "Message Queue:" << std::endl;
        do {
            std::cout << "- " << current->data << std::endl;
            current = current->next;
        } while (current != head->next);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    CircularMessageQueue messageQueue;

    for (int i = 0; i < n; i++) {
        std::string message;
        getline(std::cin, message);
        messageQueue.insertMessage(message);
    }

    // messageQueue.displayMessages();

    // messageQueue.reverseMessages();
    messageQueue.displayMessages();
    std::cout<< std::endl;

    return 0;
}
