#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int front = -1, rear = -1;
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: // Enqueue
                if ((front == (rear + 1) % SIZE)) {
                    cout << "Queue is full\n";
                } else {
                    cout << "Enter value: ";
                    cin >> val;
                    if (front == -1) { // first element
                        front = rear = 0;
                    } else {
                        rear = (rear + 1) % SIZE;
                    }
                    arr[rear] = val;
                }
                break;

            case 2: // Dequeue
                if (front == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Dequeued: " << arr[front] << "\n";
                    if (front == rear) {
                        front = rear = -1; // reset
                    } else {
                        front = (front + 1) % SIZE;
                    }
                }
                break;

            case 3: // Peek
                if (front == -1) cout << "Queue is empty\n";
                else cout << "Front element: " << arr[front] << "\n";
                break;

            case 4: // Display
                if (front == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Queue: ";
                    int i = front;
                    while (true) {
                        cout << arr[i] << " ";
                        if (i == rear) break;
                        i = (i + 1) % SIZE;
                    }
                    cout << "\n";
                }
                break;
        }
    } while (choice != 5);

    return 0;
}
