// You are using GCC
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;
    Node* prev = nullptr;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    prev->next = slow_ptr->next;
    delete slow_ptr;
}

Node* push(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    if (n % 2 != 1 || n < 3 || n > 51) {
        cout << "Invalid input. n should be odd and within the range [3, 51]." << endl;
        return 1;
    }

    Node* head = nullptr;

    for (int i = n; i >= 1; i--) {
        head = push(head, i);
    }

    deleteMiddle(head);

    display(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
