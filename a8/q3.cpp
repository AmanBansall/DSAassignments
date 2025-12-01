/*
 * Lab 8, Question 3: BST Operations (Insert, Delete, Depth)
 */
#include <iostream>
#include <algorithm> // For std::max and std::min

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

// Utility function to find the minimum node (needed for delete)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Utility function to print in-order (to check delete)
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// --- Question 3(a): Insert ---
/**
 * Inserts a new element. No duplicates are allowed.
 */
Node* insert(Node* root, int val) {
    // 1. If the tree is empty, return a new node
    if (root == NULL) {
        return new Node(val);
    }
    // 2. Recur down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    // 3. If val == root->data, do nothing
    return root;
}

// --- Question 3(b): Delete ---
/**
 * Deletes an existing element from the BST.
 */
Node* deleteNode(Node* root, int key) {
    // Base case: Key not found
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    // Key found! This is the node to be deleted
    else {
        // Case 1: Node is a leaf (no children)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Node has two children
        // Find in-order successor (smallest in the right subtree)
        else {
            Node* temp = findMin(root->right);
            // Copy the successor's data to this node
            root->data = temp->data;
            // Delete the successor from the right subtree
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// --- Question 3(c): Maximum Depth (Height) ---
/**
 * Calculates the maximum depth (or height) of the BST.
 * This is the longest path from the root to a leaf.
 */
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0; // Depth of an empty tree is 0
    } else {
        // Compute the depth of each subtree
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Use the larger one
        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

// --- Question 3(d): Minimum Depth ---
/**
 * Calculates the minimum depth of the BST.
 * This is the shortest path from the root to a leaf.
 */
int minDepth(Node* root) {
    // Base case: Empty tree
    if (root == NULL) {
        return 0;
    }
    // Case 1: Leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Case 2: Only has a right child
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    // Case 3: Only has a left child
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }

    // Case 4: Has two children
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// --- Main Function to Test ---
int main() {
    Node* root = NULL;
    
    // 3(a) Insert
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original tree (in-order): ";
    inOrder(root);
    cout << endl;

    // 3(b) Delete
    cout << "Deleting node 20 (a leaf)..." << endl;
    root = deleteNode(root, 20);
    cout << "Tree after delete: ";
    inOrder(root);
    cout << endl;

    cout << "Deleting node 70 (one child)..." << endl;
    root = deleteNode(root, 70);
    cout << "Tree after delete: ";
    inOrder(root);
    cout << endl;

    cout << "Deleting node 50 (two children)..." << endl;
    root = deleteNode(root, 50);
    cout << "Tree after delete: ";
    inOrder(root);
    cout << endl;

    // 3(c) Max Depth
    cout << "3(c): Maximum depth of the tree: " << maxDepth(root) << endl;

    // 3(d) Min Depth
    cout << "3(d): Minimum depth of the tree: " << minDepth(root) << endl;

    // Clean up memory
    deleteTree(root);
    
    return 0;
}