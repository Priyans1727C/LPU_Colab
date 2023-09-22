// You are using GCC
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

void deleteEvenPositionNodes(Node*& head) {
    if (!head) return;

    Node* current = head;
    Node* prev = nullptr;
    int position = 1;

    while (current) {
        if (position % 2 == 0) {
            Node* temp = current;
            current = current->next;
            delete temp;
            if (prev) {
                prev->next = current;
            } else {
                head = current;
            }
        } else {
            prev = current;
            current = current->next;
        }
        position++;
    }
}

void display(Node* head) {
    if (!head) return;

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

    cout << "Original Linked List: ";
    display(head);

    deleteEvenPositionNodes(head);

    cout << "Final Linked List: ";
    display(head);

    return 0;
}
