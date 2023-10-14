// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = new struct Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to build the tree

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node{data, nullptr, nullptr};
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void mirrorImage(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorImage(root->left);
    mirrorImage(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }

    cout << "Original tree: ";
    preorderTraversal(root);
    cout << endl;

    mirrorImage(root);

    cout << "Mirror Image: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
