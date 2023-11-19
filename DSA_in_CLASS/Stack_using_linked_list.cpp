#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;
node *temp = NULL;

void push()
{
    node *newnode = new node();
    cin >> newnode->data;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
    cout<<"Pushed elsement: "<<top->data<<endl;
}

void pop()
{
    if (top == NULL)
        cout << "stack is empty"<<endl;
    else
    {
        node *temp = top;
        top = top->next;
        cout<<"Poped Element: "<<temp->data<<endl;
        delete temp;
    }
}

void print()
{
    temp=top;

    cout<<"stack remaing element: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;

}

void operations()
{
    int n;

    cout<<"OPERATIONS   \n 1)PUSH\n 2)POP\n 3)PRINT \n 0)EXIT\n";
    while(n)
    {
        cout<<"Option: ";
        cin>>n;
        switch(n)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                n=0;
                break;
        }
    }
}


int main()
{
    operations();
    
}
