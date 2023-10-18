#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void postOrder() {
        postOrderRec(root);
    }

    void postOrderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        postOrderRec(root->left);
        postOrderRec(root->right);
        cout << root->data << " ";
    }

    int sumOfNodes() {
        return sumOfNodesRec(root);
    }

    int sumOfNodesRec(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return root->data + sumOfNodesRec(root->left) + sumOfNodesRec(root->right);
    }
};

int main() {
    int n;
    cin >> n;
    BST tree;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        tree.insert(data);
    }

    cout << "Post-order traversal: ";
    tree.postOrder();
    cout << "\nSum of all nodes: " << tree.sumOfNodes() << endl;

    return 0;
}
