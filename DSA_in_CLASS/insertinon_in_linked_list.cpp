#include"iostream"
using namespace std;

struct node
{
    int data;
    struct node *next;

};

int main()
{
  struct node *newnode=NULL;
  struct node *temp=NULL;
  struct node *head=NULL;
  struct node *firstnode=NULL;
  struct node *lastnode=NULL;

  int choice;
  while(choice)
  {
    newnode= new node(); 
    cout<<"data: ";
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    cout<<"choice 0/1: ";
    cin>>choice;
  }

    firstnode=new node();
    lastnode=new node();
    cout<<"insert at first: ";
    cin>>firstnode->data;
    firstnode->next=head;
    head=firstnode;


    cout<<"insert at last: ";
    cin>>lastnode->data;
    lastnode->next=0;
    temp->next=lastnode;
    temp=lastnode;
    

    temp=head;
    while(temp!=0)
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
