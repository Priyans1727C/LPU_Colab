#include <iostream>

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

void deleteNodeAtPosition(Node*& head, int position) {
    if (!head || position <= 0) return;

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;

        while (current && count < position) {
            prev = current;
            current = current->next;
            count++;
        }

        if (current) {
            prev->next = current->next;
            delete current;
        }
    }
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insert(head, data);
    }

    int position;
    cin >> position;

    deleteNodeAtPosition(head, position);

    display(head);

    return 0;
}
