#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    Student* next;

    Student(string n) : name(n), next(nullptr) {}
};

void insertNode(Student*& head, string newName, int position) {
    Student* newNode = new Student(newName);

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        Student* current = head;
        int currentPosition = 1;

        while (currentPosition < position - 1 && current->next != nullptr) {
            current = current->next;
            currentPosition++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void printRoster(Student* head) {
    Student* current = head;
    while (current != nullptr) {
        cout << current->name << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Student* head = nullptr;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        insertNode(head, name, i + 1);
    }

    string newName;
    int position;
    cin >> newName >> position;

    cout << "Current Linked List:" << endl;
    printRoster(head);

    insertNode(head, newName, position);

    cout << "Updated Linked List:" << endl;
    printRoster(head);


    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
