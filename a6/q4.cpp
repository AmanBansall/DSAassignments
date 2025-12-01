/*
 * Lab 6, Question 4: Palindrome check for Doubly Linked List
 */
#include <iostream>

using namespace std;

// Node structure for characters
struct CharNode {
    char data;
    CharNode* next;
    CharNode* prev;
    CharNode(char val) { data = val; next = NULL; prev = NULL; }
};

/**
 * Checks if a doubly linked list is a palindrome.
 */
bool isPalindrome(CharNode* head) {
    if (head == NULL) {
        return true; // An empty list is a palindrome
    }

    // 1. Find the tail of the list
    CharNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // 2. Use two pointers, one from head, one from tail
    CharNode* start = head;
    CharNode* end = tail;

    // 3. Move pointers towards the middle
    while (start != end && start->prev != end) {
        if (start->data != end->data) {
            return false; // Mismatch
        }
        start = start->next;
        end = end->prev;
    }

    return true; // No mismatches found
}

// --- Main Function to Test ---
int main() {
    // Test Case 1: Palindrome (r -> a -> d -> a -> r)
    CharNode* head1 = new CharNode('r');
    head1->next = new CharNode('a');
    head1->next->prev = head1;
    head1->next->next = new CharNode('d');
    head1->next->next->prev = head1->next;
    head1->next->next->next = new CharNode('a');
    head1->next->next->next->prev = head1->next->next;
    head1->next->next->next->next = new CharNode('r');
    head1->next->next->next->next->prev = head1->next->next->next;

    if (isPalindrome(head1)) {
        cout << "'radar' is a palindrome." << endl;
    } else {
        cout << "'radar' is NOT a palindrome." << endl;
    }

    // Test Case 2: Not Palindrome (h -> e -> l -> l -> o)
    CharNode* head2 = new CharNode('h');
    head2->next = new CharNode('e');
    head2->next->prev = head2;
    head2->next->next = new CharNode('l');
    head2->next->next->prev = head2->next;
    // ... (rest of "hello" list)

    if (isPalindrome(head2)) {
        cout << "'hello' is a palindrome." << endl;
    } else {
        cout << "'hello' is NOT a palindrome." << endl;
    }

    // (Cleanup code omitted for brevity)
    return 0;
}