#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(char data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtIndex(int index, char data) {
        if (index < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(data);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            int count = 0;
            while (current && count < index - 1) {
                current = current->next;
                count++;
            }
            if (!current) {
                cout << "Invalid position." << endl;
                return;
            }
            newNode->next = current->next;
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

int main() {
    int n;
    cin >> n;
    char inputChar;
    LinkedList linkedList;

    for (int i = 0; i < n; i++) {
        cin >> inputChar;
        linkedList.append(inputChar);
    }

    int index;
    cin >> index;
    char charToInsert;
    cin >> charToInsert;

    linkedList.insertAtIndex(index, charToInsert);

    cout << "Updated list: ";
    linkedList.display();

    return 0;
}
