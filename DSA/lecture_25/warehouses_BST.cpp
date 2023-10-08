#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 != nullptr && root2 != nullptr) {
        return (root1->data == root2->data) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }

    return false;
}

int main() {
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    int num;

    while (cin >> num && num != -1) {
        root1 = insert(root1, num);
    }

    while (cin >> num && num != -1) {
        root2 = insert(root2, num);
    }

    if (isIdentical(root1, root2)) {
        cout << "Both BSTs are identical" << endl;
    } else {
        cout << "BSTs are not identical" << endl;
    }

    return 0;
}
