/*
 * Lab 6, Question 2: Display Circular List (Repeating Head)
 */
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

/**
 * Displays the list in the format: 20 100 40 ... 20
 */
void displayRepeatingHead(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    
    // Use a do-while loop to print at least one node
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    // Print the head's value again
    cout << head->data << endl;
}

// --- Main Function to Test ---
int main() {
    // Manually create the list: 20 -> 100 -> 40 -> 80 -> 60 -> (head)
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    Node* tail = new Node(60);
    head->next->next->next->next = tail;
    tail->next = head; // Make it circular

    cout << "Circular list display:" << endl;
    displayRepeatingHead(head);
    
    // Cleanup
    delete tail;
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}