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
    void reverse() {
        Node* prev = NULL;
        Node* cur = head;
        Node* nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head = prev;
    }
    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(3); l.insertEnd(4);
    l.reverse();
    l.display();
}
