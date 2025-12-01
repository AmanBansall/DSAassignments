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
    int countAndDelete(int key) {
        int c = 0;
        while (head && head->data == key) { Node* t = head; head = head->next; delete t; c++; }
        Node* t = head;
        while (t && t->next) {
            if (t->next->data == key) { Node* d = t->next; t->next = d->next; delete d; c++; }
            else t = t->next;
        }
        return c;
    }
    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(1); l.insertEnd(3); l.insertEnd(1);
    cout << l.countAndDelete(1) << endl;
    l.display();
}
