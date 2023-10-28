//wap for bst 
//case1:insertion n elements from user
//case2:searching element in bst
//case3:traversal (in-order)
//case4:pre-order
//case5:post-order
//case6:delete a node from bst
//case7:find smallest number
//case8:find largest number
//case9:exit



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val >= root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

Node* findSmallestNode(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    
    return node;
}

Node* findLargestNode(Node* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
        Node* temp = findLargestNode(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    	}	    
    }
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes to insert into the BST: ";
    cin >> n;
    
    Node* root = NULL;
    
    cout << "Enter the values of the nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    
    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    
    cout << endl;
    
    int element;
    cout << "Enter a value to delete from the BST: ";
    cin >> element;
    root = deleteNode(root, element);

    cout << "Inorder Traversal after deletion: ";
    inorderTraversal(root);
    
    Node* smallest = findSmallestNode(root);
    Node* largest = findLargestNode(root);
    cout << "\nSmallest element in BST: " << smallest->data << endl;
    cout << "Largest element in BST: " << largest->data << endl;
    
    return  0;
}
