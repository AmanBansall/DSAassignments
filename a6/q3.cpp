/*
 * Lab 6, Question 3: Find size of (i) Doubly (ii) Circular
 */
#include <iostream>

using namespace std;

// Node structures
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val) { data = val; next = NULL; prev = NULL; }
};

struct CircularNode {
    int data;
    CircularNode* next;
    CircularNode(int val) { data = val; next = NULL; }
};


/**
 * (i) Finds the size of a Doubly Linked List
 */
int getDoublyListSize(DoublyNode* head) {
    int count = 0;
    DoublyNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/**
 * (ii) Finds the size of a Circular Linked List
 */
int getCircularListSize(CircularNode* head) {
    if (head == NULL) {
        return 0;
    }
    
    int count = 0;
    CircularNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    
    return count;
}

// --- Main Function to Test ---
int main() {
    // Test (i) Doubly List
    DoublyNode* dHead = new DoublyNode(10);
    dHead->next = new DoublyNode(20);
    dHead->next->prev = dHead;
    dHead->next->next = new DoublyNode(30);
    dHead->next->next->prev = dHead->next;

    cout << "Size of Doubly List: " << getDoublyListSize(dHead) << endl;

    // Test (ii) Circular List
    CircularNode* cHead = new CircularNode(10);
    cHead->next = new CircularNode(20);
    cHead->next->next = new CircularNode(30);
    cHead->next->next->next = new CircularNode(40);
    cHead->next->next->next->next = cHead; // Points back to head
    
    cout << "Size of Circular List: " << getCircularListSize(cHead) << endl;

    // (Cleanup code omitted for brevity)
    return 0;
}