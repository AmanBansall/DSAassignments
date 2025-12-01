/*
 * Lab 6, Question 1(b): Menu-Driven Program for CIRCULAR Linked List
 */
#include <iostream>

using namespace std;

// Node structure for a Circular Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// 
Node* tail = NULL; // Global tail pointer. tail->next points to head.

/**
 * Utility: Display the list
 */
void display() {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* head = tail->next;
    Node* temp = head;
    cout << "List (circular): ... -> ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to " << head->data << ")" << endl;
}

/**
 * (a-i) Insertion: As first node (at head)
 */
void insertAtHead(int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
        tail = newNode;
        newNode->next = tail; // Points to itself
    } else {
        newNode->next = tail->next; // New node points to old head
        tail->next = newNode;       // Tail points to new head
    }
}

/**
 * (a-ii) Insertion: As last node
 */
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
        tail = newNode;
        newNode->next = tail;
    } else {
        newNode->next = tail->next; // New node points to head
        tail->next = newNode;       // Old tail points to new node
        tail = newNode;             // New node becomes the new tail
    }
}

/**
 * (c) Search for a node
 * Helper function: Returns the node with the given value, or NULL
 */
Node* search(int key) {
    if (tail == NULL) return NULL;
    Node* head = tail->next;
    Node* temp = head;
    do {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

/**
 * (a-iii) Insertion: After a specific node
 */
void insertAfter(int key, int val) {
    Node* targetNode = search(key);
    if (targetNode == NULL) {
        cout << "Node " << key << " not found." << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = targetNode->next;
    targetNode->next = newNode;
    
    // If we inserted after the tail, the new node becomes the tail
    if (targetNode == tail) {
        tail = newNode;
    }
}

/**
 * (a-iv) Insertion: Before a specific node
 * This is less efficient, as we need to find the node *before* the target
 */
void insertBefore(int key, int val) {
    if (tail == NULL) {
        cout << "List is empty, cannot insert before." << endl;
        return;
    }
    
    Node* head = tail->next;
    Node* temp = head;
    Node* prev = tail; // Start prev at the tail

    do {
        if (temp->data == key) {
            Node* newNode = new Node(val);
            newNode->next = temp;
            prev->next = newNode;
            // If we inserted before the head, no change to tail needed
            // (unless it's a 1-node list, handled by insertAtHead)
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    
    cout << "Node " << key << " not found." << endl;
}


/**
 * (b) Deletion of a specific node
 */
void deleteNode(int key) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* head = tail->next;
    Node* current = head;
    Node* prev = tail;

    // Find the node
    do {
        if (current->data == key) {
            break; // Found it
        }
        prev = current;
        current = current->next;
    } while (current != head);

    // Check if not found
    if (current->data != key) {
        cout << "Node " << key << " not found." << endl;
        return;
    }
    
    // --- Node is found (at 'current') ---

    // Case 1: Only one node in the list
    if (current == tail && current == head) {
        tail = NULL;
    }
    // Case 2: Deleting the head node
    else if (current == head) {
        tail->next = head->next; // Tail points to new head
    }
    // Case 3: Deleting the tail node
    else if (current == tail) {
        prev->next = tail->next; // Prev points to head
        tail = prev;             // Prev becomes new tail
    }
    // Case 4: Deleting a middle node
    else {
        prev->next = current->next;
    }

    delete current;
    cout << "Node " << key << " deleted." << endl;
}


// --- Main Menu-Driven Function ---
int main() {
    int choice, val, key;

    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Node" << endl;
        cout << "4. Insert Before Node" << endl;
        cout << "5. Delete Node" << endl;
        cout << "6. Search Node" << endl;
        cout << "7. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                insertAtHead(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): "; cin >> key;
                cout << "Enter value to insert: "; cin >> val;
                insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): "; cin >> key;
                cout << "Enter value to insert: "; cin >> val;
                insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: "; cin >> val;
                deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: "; cin >> val;
                if (search(val) != NULL) {
                    cout << "Node " << val << " was found." << endl;
                } else {
                    cout << "Node " << val << " was NOT found." << endl;
                }
                break;
            case 7:
                display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    // Cleanup memory
    if (tail != NULL) {
        Node* current = tail->next;
        Node* head = tail->next;
        while(current != tail) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete tail;
    }

    return 0;
}