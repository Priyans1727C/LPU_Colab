#include "iostream"
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head, *newnode, *temp;

int main()
{
    int choice,count =0;
    while (choice)
    {
        newnode = new Node();
        cout << "enter data in node: ";
        cin >> newnode->data;
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        cout << "Do you want to continue(0,1)";
        cin >> choice;
    }

    int find,pos;
    cout<<"enter data to find: ";
    cin>>find;
    temp = head;
    while (temp != 0)
    {
        temp->data;
        ++count;
        if(   temp->data== find)
        {
            pos= count;
        }
        temp = temp->next;



    }
        cout <<"\nPosition no of nodes is: "<<pos;
}