/*
 * Lab 7, Question 2: Improved Selection Sort (Min & Max)
 */
#include <iostream>
#include <utility> // For std::swap

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    // Loop until the start and end pointers cross
    while (start < end) {
        int min_idx = start;
        int max_idx = start;

        // Find the min and max index in the current range
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }
        
        // --- Swap Min ---
        // Swap the minimum element to the 'start' position
        swap(arr[start], arr[min_idx]);

        // --- Swap Max ---
        // We must check if the max element was at the 'start' position.
        // If it was, it just got swapped to 'min_idx'.
        if (max_idx == start) {
            max_idx = min_idx;
        }

        // Swap the maximum element to the 'end' position
        swap(arr[end], arr[max_idx]);
        
        // Shrink the window
        start++;
        end--;
    }
}

// --- Main Function to Test ---
int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    improvedSelectionSort(arr, n);
    
    cout << "Sorted array:   ";
    printArray(arr, n);
    return 0;
}