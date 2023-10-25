#include"iostream"

using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node* next;

};
struct node *temp ,*head=nullptr;
int main()
{
    int choice;
    // cout 
    while(choice)
    {
        struct node*newnode =new node();
        cout<<"data: ";
        cin>>newnode->data;
        if(head==0)
        {
            head=temp=newnode;
            newnode->next=nullptr;
            newnode->prev=nullptr;
        }
        else
        {
            temp->next=newnode;
            newnode->next=nullptr;
            newnode->prev=temp;
            temp=newnode;
        }
        cout<<"enter choice: ";
        cin>>choice;
    }
    cout<<endl;
    temp=head;
    cout<<"Header link list: ";
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
