
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* deleteEvenNodes(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    root->left = deleteEvenNodes(root->left);
    root->right = deleteEvenNodes(root->right);
    
    if (root->data % 2 == 0) {
        if (root->left) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else if (root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else {
            delete root;
            return NULL;
        }
    }
    
    return root;
}

void printBST(Node* root) {
    if (root == NULL) {
        return;
    }
    
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }
    
    root = deleteEvenNodes(root);
    printBST(root);

    return 0;
}
