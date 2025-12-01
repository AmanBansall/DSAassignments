/*
 * Lab 8, Question 2: BST Functions
 */
#include <iostream>

using namespace std;

// --- Basic Node and Insert (from above) ---
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

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// --- Question 2(a): Search ---

/**
 * Search for a key in BST (Recursive)
 */
Node* searchRecursive(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data
    if (key > root->data) {
        return searchRecursive(root->right, key);
    }

    // Key is smaller than root's data
    return searchRecursive(root->left, key);
}

/**
 * Search for a key in BST (Non-Recursive / Iterative)
 */
Node* searchNonRecursive(Node* root, int key) {
    Node* current = root;
    // Loop until we reach a null node or find the key
    while (current != NULL) {
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL; // Key not found
}

// --- Question 2(b): Maximum Element ---

Node* findMax(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* current = root;
    // The max element is the rightmost node
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

// --- Question 2(c): Minimum Element ---

Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* current = root;
    // The min element is the leftmost node
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// --- Question 2(d): In-order Successor ---

/**
 * Finds the in-order successor of a given node.
 * The successor is the node that comes *after* it in an in-order traversal.
 */
Node* getSuccessor(Node* root, int key) {
    // 1. Search for the node
    Node* nodeToFind = searchRecursive(root, key);
    if (nodeToFind == NULL) {
        return NULL; // Node doesn't exist
    }

    // Case 1: Node has a right subtree
    // The successor is the minimum element in the right subtree.
    if (nodeToFind->right != NULL) {
        return findMin(nodeToFind->right);
    }

    // Case 2: Node has no right subtree
    // The successor is the lowest ancestor of the node, for which
    // the node is in its *left* subtree.
    Node* successor = NULL;
    Node* current = root;

    while (current != NULL && current->data != key) {
        if (key < current->data) {
            successor = current; // Possible successor
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

// --- Question 2(e): In-order Predecessor ---

/**
 * Finds the in-order predecessor of a given node.
 * The predecessor is the node that comes *before* it in an in-order traversal.
 */
Node* getPredecessor(Node* root, int key) {
    // 1. Search for the node
    Node* nodeToFind = searchRecursive(root, key);
    if (nodeToFind == NULL) {
        return NULL; // Node doesn't exist
    }

    // Case 1: Node has a left subtree
    // The predecessor is the maximum element in the left subtree.
    if (nodeToFind->left != NULL) {
        return findMax(nodeToFind->left);
    }

    // Case 2: Node has no left subtree
    // The predecessor is the lowest ancestor of the node, for which
    // the node is in its *right* subtree.
    Node* predecessor = NULL;
    Node* current = root;

    while (current != NULL && current->data != key) {
        if (key > current->data) {
            predecessor = current; // Possible predecessor
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return predecessor;
}

// --- Main Function to Test ---
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // 2(a) Search
    int keyToFind = 40;
    Node* result = searchNonRecursive(root, keyToFind);
    if (result != NULL) {
        cout << "2(a): Found key " << keyToFind << endl;
    } else {
        cout << "2(a): Key " << keyToFind << " not found" << endl;
    }

    // 2(b) Max Element
    Node* maxNode = findMax(root);
    cout << "2(b): Maximum element is " << maxNode->data << endl;

    // 2(c) Min Element
    Node* minNode = findMin(root);
    cout << "2(c): Minimum element is " << minNode->data << endl;

    // 2(d) In-order Successor
    int nodeKey = 30;
    Node* successor = getSuccessor(root, nodeKey);
    if (successor != NULL) {
        cout << "2(d): Successor of " << nodeKey << " is " << successor->data << endl;
    } else {
        cout << "2(d): " << nodeKey << " has no successor" << endl;
    }

    // 2(e) In-order Predecessor
    nodeKey = 70;
    Node* predecessor = getPredecessor(root, nodeKey);
    if (predecessor != NULL) {
        cout << "2(e): Predecessor of " << nodeKey << " is " << predecessor->data << endl;
    } else {
        cout << "2(e): " << nodeKey << " has no predecessor" << endl;
    }

    // Clean up memory
    deleteTree(root);
    
    return 0;
}