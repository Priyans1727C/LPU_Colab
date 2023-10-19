#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* createNode(int value) {
    return new Node(value);
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

bool searchKey(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return searchKey(root->left, key);
    } else {
        return searchKey(root->right, key);
    }
}

int main() {
    int numNodes;
    cin >> numNodes;

    Node* root = nullptr;

    for (int i = 0; i < numNodes; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int key;
    cin >> key;

    if (searchKey(root, key)) {
        cout << "The key " << key << " is found in the binary search tree" << endl;
    } else {
        cout << "The key " << key << " is not found in the binary search tree" << endl;
    }

    return 0;
}
