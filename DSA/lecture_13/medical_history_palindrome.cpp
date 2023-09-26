// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        vector<int> medicalEvents;
        Node* current = head;
        while (current) {
            medicalEvents.push_back(current->data);
            current = current->next;
        }

        int left = 0;
        int right = medicalEvents.size() - 1;

        while (left < right) {
            if (medicalEvents[left] != medicalEvents[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList patientHistory;

    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;
        patientHistory.insert(event);
    }

    if (patientHistory.isPalindrome()) {
        cout << "The patient's medical history is a palindrome" << endl;
    } else {
        cout << "The patient's medical history is not a palindrome" << endl;
    }

    return 0;
}
