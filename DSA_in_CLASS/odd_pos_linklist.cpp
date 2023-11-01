#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *append(Node *head, string data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head)
        head = newNode;
    else
    {
        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }

    return head;
}

Node *deleteAlternateNodes(Node *head)
{
    if (!head)
        return nullptr;

    Node *current = head;
    while (current && current->next)
    {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        current = current->next;
    }

    return head;
}

void display(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    Node *head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string data;
        cin >> data;
        head = append(head, data);
    }

    display(head);

    head = deleteAlternateNodes(head);

    display(head);

    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
