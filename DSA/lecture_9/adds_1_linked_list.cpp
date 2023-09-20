// You are using GCC
#include <iostream>

using namespace std;

class Node {
public:
    int digit;
    Node* next;

    Node(int digit) {
        this->digit = digit;
        this->next = nullptr;
    }
};

class Barcode {
public:
    Node* head;

    Barcode() {
        head = nullptr;
    }

    void insert(int digit) {
        Node* newNode = new Node(digit);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void addOne() {
        Node* current = head;
        Node* lastNonNine = nullptr;

        // Find the rightmost non-nine digit (if any)
        while (current) {
            if (current->digit != 9) {
                lastNonNine = current;
            }
            current = current->next;
        }

        // Add 1 to the rightmost non-nine digit (if any)
        if (lastNonNine) {
            lastNonNine->digit++;
        } else {
            // If all digits are 9, create a new node for carry
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        // Reset all digits to the right of the modified digit to 0
        current = lastNonNine ? lastNonNine->next : head;
        while (current) {
            current->digit = 0;
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->digit << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Barcode barcode;

    for (int i = 0; i < n; ++i) {
        int digit;
        cin >> digit;
        barcode.insert(digit);
    }

    // cout << "Original Barcode: ";
    // barcode.display();

    barcode.addOne();

    // cout << "Modified Barcode: ";
    barcode.display();

    return 0;
}
