#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int kthSmallest(Node* root, int& k) {
    if (root == nullptr) {
        return -1; 
    }

    int leftResult = kthSmallest(root->left, k);

    if (leftResult != -1) {
        return leftResult;
    }

    k--;
    if (k == 0) {
        return root->data;
    }

    return kthSmallest(root->right, k);
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    int num;
    Node* root = nullptr;

    while (ss >> num) {
        if (num == -1) {
            break;
        }
        root = insertNode(root, num);
    }

    int k;
    cin >> k;

    int result = kthSmallest(root, k);

    cout << result << endl;

    return 0;
}
