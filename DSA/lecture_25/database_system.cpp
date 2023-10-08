#include <iostream>
#include <set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree based on the given input
Node* buildBinaryTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = createNode(data);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

// In-order traversal to check for duplicates
bool hasDuplicateValues(Node* root, set<int>& seen) {
    if (root == NULL)
        return false;

    // Recursively check left subtree
    if (hasDuplicateValues(root->left, seen))
        return true;

    // Check if the current node's data is already seen
    if (seen.find(root->data) != seen.end())
        return true;

    seen.insert(root->data);

    // Recursively check right subtree
    if (hasDuplicateValues(root->right, seen))
        return true;

    return false;
}

int main() {
    Node* root = buildBinaryTree();
    set<int> seen; // To store seen customer IDs

    if (hasDuplicateValues(root, seen)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
