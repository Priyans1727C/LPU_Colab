#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNodesInRange(Node*& head, int start, int end) {
    if (!head) return;

    Node* current = head;
    Node* prev = nullptr;
    int position = 1;

    while (current && position < start) {
        prev = current;
        current = current->next;
        position++;
    }

    while (current && position <= end) {
        Node* temp = current;
        current = current->next;
        delete temp;
        position++;
    }

    if (prev) {
        prev->next = current;
    } else {
        head = current;
    }
}

void display(Node* head) {
    if (!head) {
        cout << "all the elements are deleted" << endl;
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size;

    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        insert(head, data);
    }

    int start, end;
    cin >> start >> end;

    cout << "Linked List before deletion: ";
    display(head);

    deleteNodesInRange(head, start, end);

    cout << "Linked List after deletion: ";
    display(head);

    return 0;
}
