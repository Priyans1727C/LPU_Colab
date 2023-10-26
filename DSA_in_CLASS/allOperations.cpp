#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;
node *temp = NULL;
node *newnode = NULL;

void creation()
{
    int n;

    cout << "Enter no of node:";
    cin >> n;
    cout << "enter data: ";
    for (int i = 0; i < n; i++)
    {
        newnode = new node();
        cin >> newnode->data;
        newnode->next = nullptr;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp=head;
}
void display()
{
    temp = head;
    cout << endl
         << endl
         << "Element are: " << endl;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void deleteNode(node *&temp, int val)
{
    if(temp->data==val)
    {
        node *curr=new node();
        curr=temp;
        temp=temp->next;
        delete curr;
        return;
    }
    else
    deleteNode(temp->next,val);
}
void delLastnode(node* &temp)
{
    if(temp->next==NULL)
    {
        node *curr=temp;
        temp=temp->next;
        delete curr;
        return;
    }
    delLastnode(temp->next);
}
void insertAfterNode(node *&temp,int val)
{
    if(temp->data==val)
    {
        newnode=new node();
        cout<<"Data: ";
        cin>>newnode->data;
        newnode->next=temp->next;
        temp->next=newnode;
        return;
    }
    insertAfterNode(temp->next,val);
}

void insertbef(node *&temp,int val)
{
    if(temp->next->data==val)
    {
        newnode= new node();
        cout<<"val : ";
        cin>>newnode->data;
        newnode->next=temp->next;
        temp->next=newnode;
        return;
    }
    insertbef(temp->next,val);

}

int main()
{
    int ch;
    int val;
 
 cout<<"\nOptions:\n    1)Creation\n    2)Delete Current Node\n    3)Display\n    4)delete last node\n    5)Insert after given node\n    6)Insert before given node\n\n";

    while (ch)
    {
        cout << "Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            creation();
            break;
        case 2:
            cout << "Enter value which you want to delete: ";
            cin >> val;
            deleteNode(temp,val);
            temp=head;
            break;
        case 3:
            display();
            temp=head;
            break;
        case 4:
            delLastnode(temp);
            temp=head;
            break;
        case 5:
            cout << "Enter value which you want to insert after node:: ";
            cin >> val;
            insertAfterNode(temp,val);
            temp=head;
            break;
        case 6:
            cout<<"Enter value which you want to insert before node :";
            cin>>val;
            temp=head;
            insertbef(temp,val);
            break;
        }
    }
}
