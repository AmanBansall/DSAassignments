#include <iostream>
using namespace std;

int main() {
    int q[100];
    int front = -1, rear = -1;
    int choice, x;

    cout << "Stack using one queue\n";
    cout << "Menu: 1.push  2.pop  3.top  4.exit\n";

    do {
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {  // push
            cout << "Enter value: ";
            cin >> x;

            if (front == -1) front = 0;
            q[++rear] = x;

            // rotate older elements behind new one
            for (int i = 0; i < rear - front; i++) {
                q[++rear] = q[front];
                front++;
            }

            cout << "Pushed " << x << "\n";
        }

        else if (choice == 2) {  // pop
            if (front == -1 || front > rear) {
                cout << "Stack empty\n";
            } else {
                cout << "Popped: " << q[front] << "\n";
                front++;
                if (front > rear) { front = rear = -1; }
            }
        }

        else if (choice == 3) {  // top
            if (front == -1 || front > rear) cout << "Stack empty\n";
            else cout << "Top: " << q[front] << "\n";
        }

    } while (choice != 4);

    return 0;
}
