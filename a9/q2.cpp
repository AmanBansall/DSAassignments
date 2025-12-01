/*
 * Lab 9, Question 2: Priority Queues using Heaps
 */
#include <iostream>
#include <algorithm> // For std::swap
#include <climits>   // For error codes

using namespace std;

// Class to manage a Heap, which acts as a Priority Queue
class PriorityQueue {
private:
    int* arr;       // Pointer to the array
    int capacity;   // Maximum size
    int heap_size;  // Current number of elements
    bool isMaxHeap; // True for Max-PQ, false for Min-PQ

    // Helper functions for indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    /**
     * The "bubble-down" function (heapify)
     */
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int target = i; // Target to swap with (largest or smallest)

        if (isMaxHeap) {
            // Max-Heap: find the largest
            if (l < heap_size && arr[l] > arr[target])
                target = l;
            if (r < heap_size && arr[r] > arr[target])
                target = r;
        } else {
            // Min-Heap: find the smallest
            if (l < heap_size && arr[l] < arr[target])
                target = l;
            if (r < heap_size && arr[r] < arr[target])
                target = r;
        }

        if (target != i) {
            swap(arr[i], arr[target]);
            heapify(target); // Recurse down
        }
    }

public:
    // Constructor
    PriorityQueue(int cap, bool maxHeap) {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
        isMaxHeap = maxHeap;
    }

    // Destructor (to free memory)
    ~PriorityQueue() {
        delete[] arr;
    }

    /**
     * Inserts a new element into the priority queue.
     */
    void insert(int key) {
        if (heap_size == capacity) {
            cout << "Overflow: Could not insert key" << endl;
            return;
        }

        // 1. Insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        arr[i] = key;

        // 2. Fix the heap property ("bubble-up")
        if (isMaxHeap) {
            // Max-Heap: bubble up if child > parent
            while (i != 0 && arr[parent(i)] < arr[i]) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        } else {
            // Min-Heap: bubble up if child < parent
            while (i != 0 && arr[parent(i)] > arr[i]) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
    }

    /**
     * Extracts the top-priority element (max or min)
     */
    int extractTop() {
        if (heap_size <= 0) {
            cout << "Error: Priority Queue is empty" << endl;
            return isMaxHeap ? INT_MIN : INT_MAX; // Error code
        }
        if (heap_size == 1) {
            heap_size--;
            return arr[0];
        }

        // 1. Store the root (top priority)
        int root = arr[0];

        // 2. Move the last element to the root
        arr[0] = arr[heap_size - 1];
        heap_size--;

        // 3. "Bubble-down" to fix the heap
        heapify(0);

        return root;
    }

    /**
     * Returns the top-priority element without removing it.
     */
    int peek() {
        if (heap_size <= 0) {
            cout << "Error: Priority Queue is empty" << endl;
            return isMaxHeap ? INT_MIN : INT_MAX; // Error code
        }
        return arr[0];
    }
};

// --- Main Function to Test ---
int main() {
    cout << "--- Testing Max-Priority Queue ---" << endl;
    // Create a Max-PQ (higher number = higher priority)
    PriorityQueue maxPQ(10, true);
    
    maxPQ.insert(30);
    maxPQ.insert(50);
    maxPQ.insert(10);
    maxPQ.insert(20);
    maxPQ.insert(40);

    cout << "Top element is: " << maxPQ.peek() << endl; // Should be 50

    cout << "Extracting elements: ";
    cout << maxPQ.extractTop() << " "; // 50
    cout << maxPQ.extractTop() << " "; // 40
    cout << maxPQ.extractTop() << " "; // 30
    cout << endl;
    
    cout << "\n--- Testing Min-Priority Queue ---" << endl;
    // Create a Min-PQ (lower number = higher priority)
    PriorityQueue minPQ(10, false);
    
    minPQ.insert(30);
    minPQ.insert(50);
    minPQ.insert(10);
    minPQ.insert(20);
    minPQ.insert(40);

    cout << "Top element is: " << minPQ.peek() << endl; // Should be 10

    cout << "Extracting elements: ";
    cout << minPQ.extractTop() << " "; // 10
    cout << minPQ.extractTop() << " "; // 20
    cout << minPQ.extractTop() << " "; // 30
    cout << endl;

    return 0;
}