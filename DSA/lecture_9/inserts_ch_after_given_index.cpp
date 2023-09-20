#include <iostream>

struct Node {
    char data;
    Node* next;
};

Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* insertAfterIndex(Node* head, int index, char value) {
    Node* newNode = createNode(value);

    if (index == -1) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        if (current == nullptr) {
            std::cout << "Invalid index." << std::endl;
            return head;
        }
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        std::cout << "Invalid index." << std::endl;
    }

    return head;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    int n;
    char value;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> value;

        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int index;
    std::cin >> index;

    std::cin >> value;

    head = insertAfterIndex(head, index, value);

    std::cout << "Updated list: ";
    displayList(head);

    return 0;
}
