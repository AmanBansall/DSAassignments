#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(NULL) {}
    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->data : -1;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(3); l.insertEnd(4); l.insertEnd(5);
    cout << l.findMiddle() << endl;
}
