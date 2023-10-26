#include<bits/stdc++.h>

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

void display_inorder(struct Node *root)
{
        if(root==NULL)
        return;
    display_inorder(root->left);
    cout<<root->data<<"->";
    display_inorder(root->right); 
}

void display_preorder(struct Node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"->";
    display_preorder(root->left);
    display_preorder(root->right); 
}

void display_postorder(struct Node *root)
{
        if(root==NULL)
        return;
    display_postorder(root->left);
    display_postorder(root->right); 
    cout<<root->data<<"->";
}



int main()
{
    Node*root =NULL;
    int numNodes,value,key,choice;
    cin>>numNodes;
    for(int i=0;i<numNodes;i++)
    {
        cin>>value;
        root=insertNode(root,value);
    }
    cout<<endl<<"choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            display_preorder(root);
            cout<<endl;
            break;
        case 2:
            display_inorder(root);
            cout<<endl;
            break;
    }

}