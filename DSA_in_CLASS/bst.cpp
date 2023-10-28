#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * left;
    Node* right;
};
Node *createNode(int val)
{
    Node *newNode =new Node();
    if(!newNode)
    {
        return NULL;
    }
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* insertNode(Node* root, int val)
{
    if(root==NULL)
    {
        return createNode(val);
    }
    if(val<root->data)
    {
        root->left=insertNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=insertNode(root->right,val);
    }
    return root;
}

bool searchKey(Node* root,int key)
{
    while(root !=NULL)
    {
        if(key==root->data)
            return true;
        else if(key<root->data)
            root=root->left;
        else    
            root=root->right;
    }
    return false;
}
int main()
{
    Node*root =NULL;
    int numNodes,value,key;
    cin>>numNodes;
    for(int i=0;i<numNodes;i++)
    {
        cin>>value;
        root=insertNode(root,value);
    }

    cin>>key;
    bool found=searchKey(root,key);
    if(found)
        cout<<"The key "<<key<<" is found!";
    else
        cout<<"The key "<<key<<" is not found!";
}