// You are using GCC
#include <iostream>

using namespace std;

class Node {
public:
    int studentID;
    Node* next;

    Node(int id) {
        studentID = id;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int id) {
        Node* newNode = new Node(id);

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

    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->studentID << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList students;

    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        students.insert(id);
    }

    students.deleteFirst();

    students.display(); 

    return 0;
}
