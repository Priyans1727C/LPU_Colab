#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert data in a sorted manner
void sortedInsert(Node** head, Node* newNode) {
    if (*head == NULL || newNode->data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "Empty linked list" << endl;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to check if an element exists in the linked list
bool exists(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to get the union of two linked lists
Node* makeUnion(Node* head1, Node* head2) {
    Node* result = NULL;

    // Traverse the first linked list and add distinct elements to the result
    Node* temp1 = head1;
    while (temp1 != NULL) {
        if (!exists(result, temp1->data)) {
            Node* newNode = createNode(temp1->data);
            sortedInsert(&result, newNode);
        }
        temp1 = temp1->next;
    }

    // Traverse the second linked list and add distinct elements to the result
    Node* temp2 = head2;
    while (temp2 != NULL) {
        if (!exists(result, temp2->data)) {
            Node* newNode = createNode(temp2->data);
            sortedInsert(&result, newNode);
        }
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    int n1, n2;
    cin >> n1;

    Node* head1 = NULL;

    for (int i = 0; i < n1; i++) {
        int data;
        cin >> data;
        Node* newNode = createNode(data);
        sortedInsert(&head1, newNode);
    }

    cin >> n2;

    Node* head2 = NULL;

    for (int i = 0; i < n2; i++) {
        int data;
        cin >> data;
        Node* newNode = createNode(data);
        sortedInsert(&head2, newNode);
    }

    cout << "First Linked List: ";
    display(head1);

    cout << "Second Linked List: ";
    display(head2);

    Node* unionList = makeUnion(head1, head2);

    cout << "Union Linked List: ";
    display(unionList);

    return 0;
}
