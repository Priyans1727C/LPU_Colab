#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

node* head=NULL;
node* temp=NULL;
node* newnode=NULL;
node* tail=NULL;

void insertion()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        newnode= new node();
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    tail=temp;
}

void insertNpos(int n)
{
    newnode=new node();
    temp=head;
    while(--n)
    {
        temp=temp->next;
    }
    cin>>newnode->data;
    newnode->prev=temp;
    newnode->next=temp->next;
    newnode->next->prev=newnode;
    temp->next=newnode;
}

void print()
{
    temp=tail;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}

int main()
{
    insertion();
    // print();
    cout<<endl;
    insertNpos(3);
    cout<<endl;
    print();
}

