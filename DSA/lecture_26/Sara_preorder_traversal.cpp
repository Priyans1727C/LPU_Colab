#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

int isIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }

    return 0;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);

    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    for (int i = 0; i < n1; i++) {
        int data;
        scanf("%d", &data);
        root1 = insertNode(root1, data);
    }

    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int data;
        scanf("%d", &data);
        root2 = insertNode(root2, data);
    }

    if (isIdentical(root1, root2)) {
        printf("The two binary trees are identical.\n");
    } else {
        printf("The two binary trees are not identical.\n");
    }

    return 0;
}
