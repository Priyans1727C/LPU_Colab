#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <climits> 

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool isBSTUtil(struct node* node, int min, int max) {
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return (isBSTUtil(node->left, min, node->data - 1) &&
            isBSTUtil(node->right, node->data + 1, max));
}

int isBST(struct node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX) ? 1 : 0;
}

struct node* buildTree() {
    int data;
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct node* root = newNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    struct node* root = buildTree();

    if (isBST(root)) {
        printf("The given binary tree is a BST\n");
    } else {
        printf("The given binary tree is not a BST\n");
    }

    return 0;
}
