#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int q[SIZE], newQ[SIZE], firstHalf[SIZE];
    int n;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    if (n % 2 != 0) {
        cout << "Queue must have even number of elements\n";
        return 0;
    }

    int half = n / 2;
    int k = 0;

    // Copy first half
    for (int i = 0; i < half; i++) {
        firstHalf[i] = q[i];
    }

    // Interleave
    for (int i = 0; i < half; i++) {
        newQ[k++] = firstHalf[i];   // from first half
        newQ[k++] = q[half + i];    // from second half
    }

    // Print result
    cout << "Interleaved queue: ";
    for (int i = 0; i < n; i++) {
        cout << newQ[i] << " ";
    }
    cout << "\n";

    return 0;
}
