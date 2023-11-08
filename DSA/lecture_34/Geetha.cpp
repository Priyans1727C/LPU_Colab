
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (!root) {
        return create(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int sumGtr(Node* root, int value) {
    if (!root) {
        return 0;
    }

    int sum = 0;
    if (root->data > value) {
        sum += root->data;
    }

    sum += sumGtr(root->left, value);
    sum += sumGtr(root->right, value);

    return sum;
}

int main() {
    Node* root = nullptr;
    int n, data, target;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }
    cin >> target;

    int result = sumGtr(root, target);
    cout << result << endl;

    return 0;
}
