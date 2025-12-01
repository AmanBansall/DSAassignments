/*
 * Lab 8, Question 4: Determine if a Binary Tree is a BST
 */
#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

// --- Basic Node (from above) ---
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


/**
 * Helper function to check if a tree is a BST.
 * It checks if every node's data is within a valid range [minVal, maxVal].
 */
bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    // Base case: An empty tree is a BST
    if (root == NULL) {
        return true;
    }

    // Check the current node's value
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    // Recursively check the left and right subtrees
    // Left subtree: all values must be less than root->data (new maxVal)
    // Right subtree: all values must be greater than root->data (new minVal)
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

/**
 * Main function to determine if a tree is a BST.
 */
bool isBST(Node* root) {
    // We use long long for min/max to handle cases where
    // the node data is INT_MIN or INT_MAX.
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// --- Main Function to Test ---
int main() {
    // Test Case 1: A valid BST
    Node* validBST = new Node(50);
    validBST->left = new Node(30);
    validBST->right = new Node(70);
    validBST->left->left = new Node(20);
    validBST->left->right = new Node(40);

    if (isBST(validBST)) {
        cout << "Test 1: The first tree is a valid BST." << endl;
    } else {
        cout << "Test 1: The first tree is NOT a BST." << endl;
    }

    // Test Case 2: An invalid BST
    // 60 is in the left subtree of 50, but 60 > 50
    Node* invalidBST = new Node(50);
    invalidBST->left = new Node(30);
    invalidBST->right = new Node(70);
    invalidBST->left->right = new Node(60); // This node violates the BST property

    if (isBST(invalidBST)) {
        cout << "Test 2: The second tree is a valid BST." << endl;
    } else {
        cout << "Test 2: The second tree is NOT a BST." << endl;
    }

    // Clean up memory
    deleteTree(validBST);
    deleteTree(invalidBST);
    
    return 0;
}