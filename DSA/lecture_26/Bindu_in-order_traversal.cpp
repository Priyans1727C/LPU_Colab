// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }
    inorderTraversal(root);
    return 0;
}
