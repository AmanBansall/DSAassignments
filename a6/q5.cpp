/*
 * Lab 6, Question 5: Check if a linked list is Circular
 */
#include <iostream>

using namespace std;

// Standard singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

/**
 * Checks if a list is circular using Floyd's Cycle-Detection.
 */
bool isCircular(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* slow = head; // The tortoise
    Node* fast = head; // The hare

    //     
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // If they meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches NULL, there is no cycle
    return false;
}

// --- Main Function to Test ---
int main() {
    // Test Case 1: Circular List
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);
    head1->next->next->next->next = head1->next; // Cycle back to 20

    if (isCircular(head1)) {
        cout << "List 1 is Circular." << endl;
    } else {
        cout << "List 1 is NOT Circular." << endl;
    }

    // Test Case 2: Normal (NULL-terminated) List
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    if (isCircular(head2)) {
        cout << "List 2 is Circular." << endl;
    } else {
        cout << "List 2 is NOT Circular." << endl;
    }

    // (Cleanup code omitted for brevity)
    return 0;
}