// You are using GCC
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

//Function to build the tree
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key<= root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

//Function to perform the inorder traversal
void inorder(Node* root) {
       if (root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
    
}

int main() {
    Node* root = nullptr;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        root = insert(root, key);
    }

    inorder(root);

    return 0;
}
