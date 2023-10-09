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

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

int findPredecessor(Node* root, int value) {
    int predecessor = -1;
    while (root != nullptr) {
        if (value <= root->data) {
            root = root->left;
        } else {
            predecessor = root->data;
            root = root->right;
        }
    }
    return predecessor;
}

int main() {
    int N, M;
    cin >> N;

    Node* root = nullptr;

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }

    cin >> M;

    int predecessor = findPredecessor(root, M);

    if (predecessor != -1) {
        cout << "Inorder Predecessor: " << predecessor << endl;
    } else {
        cout << "Doesn't exist" << endl;
    }

    return 0;
}
