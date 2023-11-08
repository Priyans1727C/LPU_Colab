
#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to perform inorder traversal and print even values
void inorderPrintEven(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrintEven(root->left);
    if (root->data % 2 == 0) {
        printf("%d ", root->data);
    }
    inorderPrintEven(root->right);
}

// Main function for testing
int main() {
    // Get user input for the number of enchanted seeds
    int n;
    scanf("%d", &n);
    // Initialize the Evenness Emissary (BST)
    struct Node* emissary = NULL;
    // Plant the enchanted seeds
    for (int i = 0; i < n; i++) {
        int seed;
        scanf("%d", &seed);
        emissary = insert(emissary, seed);
    }
    // Print the even values using inorder traversal
    inorderPrintEven(emissary);
    return 0;
}
