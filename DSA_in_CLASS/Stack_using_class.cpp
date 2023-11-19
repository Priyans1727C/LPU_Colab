#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

    // Node()
    // {
    //     next = NULL;
    // }

public:
    void push();
    void pop();
    void print();
    
};

Node *top = NULL;

void Node::push()
{
    Node *newnode = new Node();
    cin >> newnode->data;
    newnode->next = NULL;
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

void Node::pop()
{
    if(top==NULL)
        cout<<"stack is empty"<<endl;
    else
    {
        top=top->next;

    }
}

void Node:: print()
{
    while (top!=NULL)
    {
        cout<<top->data<<" ";
        pop();
    }
}

int main()
{
    Node mystack;

    for(int i=0;i<5;i++)
    {
        mystack.push();
    }
    mystack.pop();
    mystack.print();
}
