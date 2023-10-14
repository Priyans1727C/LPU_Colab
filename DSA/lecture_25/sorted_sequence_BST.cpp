// You are using GCC
#include <stdio.h>
#include <stdbool.h>
#include <climits> 

// Function to check if an array represents an inorder traversal of a BST
bool isValidInorder(int arr[], int n) {
    if (n == 0) {
        return true;
    }

    int prev = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= prev) {
            return false;
        }
        prev = arr[i];
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isValidInorder(arr, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
