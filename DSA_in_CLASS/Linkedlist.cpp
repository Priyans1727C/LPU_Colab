#include"iostream"
using namespace std;

struct node
{
    int data;
    struct node*next;
};

int main()
{
    struct node* head=NULL;
    struct node* temp=NULL;
    struct node* newnode=NULL;
    struct node* last=NULL;
    last=new node();

    int choice;
    while(choice)
    {
        newnode=new node();
        cout<<"data: ";
        cin>>newnode->data;
        newnode->next=0;
        if(head==0)
        {
           temp= head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"choice 0/1: ";
        cin>>choice;

    }

temp=head;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

}
