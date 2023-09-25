#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // Circular connection
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Circular connection
        }
    }

    void display() {
        if (!head) {
            cout << "Empty List";
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
    }

    vector<int> toVector() {
        vector<int> result;
        if (!head) {
            return result;
        }
        Node* current = head;
        do {
            result.push_back(current->data);
            current = current->next;
        } while (current != head);
        return result;
    }
};

vector<int> findIntersection(CircularLinkedList& list1, CircularLinkedList& list2) {
    unordered_set<int> set1;
    unordered_set<int> intersectionSet;
    
    vector<int> result;

    vector<int> elements1 = list1.toVector();
    vector<int> elements2 = list2.toVector();

    for (int val : elements1) {
        set1.insert(val);
    }

    for (int val : elements2) {
        if (set1.count(val) > 0) {
            intersectionSet.insert(val);
        }
    }

    for (int val : intersectionSet) {
        result.push_back(val);
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t) {
        t=0;
        int n;
        cin >> n;

        CircularLinkedList list1;
        CircularLinkedList list2;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            list1.insert(val);
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            list2.insert(val);
        }

        cout << "List 1: ";
        list1.display();
        cout << endl;

        cout << "List 2: ";
        list2.display();
        cout << endl;

        vector<int> intersection = findIntersection(list1, list2);

        cout << "Intersection: ";
        for (int val : intersection) {
            cout << val << " ";
        }
        cout << endl;

        // Add a newline to separate test cases
        if (t > 0) {
            cout << endl;
        }
    }

    return 0;
}
