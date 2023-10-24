#include<bits/stdc++.h>

using namespace std;

#define MAX 3

class Stack{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top=-1;
    }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x)
{
    (top>=(MAX-1))?cout<<"stack overflow\n":cout<<"pushed into stack\n";
    if(top<(MAX-1))a[++top]=x;
    return true;
}

int Stack::pop()
{
    if(top==-1)
    {
        cout<<"stack is empty";
        return 0;
    }

    else
    {
        int x=a[top--];
        return x;
    }
}

int Stack::peek()
{
    if(top<0)
    {
        cout<<"Stack is Empty";
    }
    else
    {
        int x=a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top<0);
}


int main()
{
    Stack s;
    s.push(10);
    s.push(11);
    s.push(12);
    cout<<s.peek()<<endl;
    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
}