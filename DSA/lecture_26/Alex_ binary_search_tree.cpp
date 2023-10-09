#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}


void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    int value;
    Node* root = nullptr;

    while (cin >> value && value > 0) {
        root = insertNode(root, value);
    }

    preOrderTraversal(root);
    cout << endl;

    return 0;
}
