#include <iostream>
using namespace std;

int main() {
    int q1[100], q2[100];
    int front1 = -1, rear1 = -1;   // queue1
    int front2 = -1, rear2 = -1;   // queue2
    int choice, x;

    cout << "Stack using two queues\n";
    cout << "Menu: 1.push  2.pop  3.top  4.exit\n";

    do {
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {  // push
            cout << "Enter value: ";
            cin >> x;

            // put in q2
            if (front2 == -1) front2 = 0;
            q2[++rear2] = x;

            // move all from q1 to q2
            while (front1 != -1 && front1 <= rear1) {
                q2[++rear2] = q1[front1++];
            }

            // copy q2 -> q1
            front1 = 0; rear1 = rear2;
            for (int i = 0; i <= rear2; i++) {
                q1[i] = q2[i];
            }

            // reset q2
            front2 = -1; rear2 = -1;

            cout << "Pushed " << x << "\n";
        }

        else if (choice == 2) {  // pop
            if (front1 == -1 || front1 > rear1) {
                cout << "Stack empty\n";
            } else {
                cout << "Popped: " << q1[front1] << "\n";
                front1++;
                if (front1 > rear1) { front1 = rear1 = -1; }
            }
        }

        else if (choice == 3) {  // top
            if (front1 == -1 || front1 > rear1) cout << "Stack empty\n";
            else cout << "Top: " << q1[front1] << "\n";
        }

    } while (choice != 4);

    return 0;
}
