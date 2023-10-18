#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    int taskID;

    std::cout << "Input:\n";
    while (true) {
        std::cin >> taskID;
        if (taskID == -1) {
            break;
        }
        insert(root, taskID);
    }

    std::cout << "\nOutput:\nPost order Traversal:\n";
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
