#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};


Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return leftRotate(root);
    }

    return root;
}



void inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {

    int n,input;
    cin>>n;
    Node* root = nullptr;

    for(int i=0;i<n;i++)
    {
        cin>>input;
        root = insert(root,input);
    }
   

    cout << "inOrder traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
