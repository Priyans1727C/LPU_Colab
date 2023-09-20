#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    if (newNode == NULL) {
        cout << "Memory allocation failed!";
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    if (head == NULL)
        head = createNode(data);
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(data);
    }
    return head;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* addTwoLists(Node* first, Node* second) {
    Node* res = NULL;
    Node* prev = NULL;
    Node* temp = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        temp = createNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = createNode(carry);

    return reverseList(res);
}

void displayList(Node* head) {
    if (head == NULL) {
        cout << "Empty List!";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int N, M;
    cin >> N;
    Node* first = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        first = insertNode(first, value);
    }
    cin >> M;
    Node* second = NULL;
    for (int i = 0; i < M; i++) {
        int value;
        cin >> value;
        second = insertNode(second, value);
    }

    cout << "First linked list: ";
    displayList(first);
    cout << "Second linked list: ";
    displayList(second);

    // Reverse the linked lists to perform addition
    Node* reversedFirst = reverseList(first);
    Node* reversedSecond = reverseList(second);

    Node* result = addTwoLists(reversedFirst, reversedSecond);

    cout << "Total Sales: ";
    displayList(result);

    // Delete the linked lists
    deleteList(first);
    deleteList(second);
    deleteList(result);

  return 0;

}
